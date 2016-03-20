using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.IO;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using Windows.Data.Json;
using Windows.Storage;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.Web.Syndication;

// Модель данных, определяемая этим файлом, служит типичным примером строго типизированной
// по умолчанию.  Имена свойств совпадают с привязками данных из стандартных шаблонов элементов.
//
// Приложения могут использовать эту модель в качестве начальной точки и добавлять к ней дополнительные элементы или полностью удалить и
// заменить ее другой моделью, соответствующей их потребностям. Использование этой модели позволяет повысить качество приложения 
// скорость реагирования, инициируя задачу загрузки данных в коде программной части для App.xaml, если приложение 
// запускается впервые.

namespace RssApp.Data
{
    /// <summary>
    /// Универсальная модель данных элементов.
    /// </summary>
    public class SampleDataItem
    {
        public SampleDataItem(String uniqueId, String title, String subtitle, String imagePath, String description, String content)
        {
            this.UniqueId = uniqueId;
            this.Title = title;
            this.Subtitle = subtitle;
            this.Description = description;
            this.ImagePath = imagePath;
            this.Content = content;
        }

        public string UniqueId { get; private set; }
        public string Title { get; private set; }
        public string Subtitle { get; private set; }
        public string Description { get; private set; }
        public string ImagePath { get; private set; }
        public string Content { get; private set; }

        public override string ToString()
        {
            return this.Title;
        }
    }

    /// <summary>
    /// Универсальная модель данных групп.
    /// </summary>
    public class SampleDataGroup
    {
        public SampleDataGroup(String uniqueId, String title, String subtitle, String imagePath, String description)
        {
            this.UniqueId = uniqueId;
            this.Title = title;
            this.Subtitle = subtitle;
            this.Description = description;
            this.ImagePath = imagePath;
            this.Items = new ObservableCollection<SampleDataItem>();
        }

        public string UniqueId { get; private set; }
        public string Title { get; private set; }
        public string Subtitle { get; private set; }
        public string Description { get; private set; }
        public string ImagePath { get; set; }
        public ObservableCollection<SampleDataItem> Items { get; private set; }

        public override string ToString()
        {
            return this.Title;
        }
    }

    /// <summary>
    /// Создает коллекцию групп и элементов с содержимым, считываемым из статического JSON-файла.
    /// 
    /// SampleDataSource инициализируется данными, считываемыми из статического JSON-файла, включенного в 
    /// проект.  Предоставляет пример данных как во время разработки, так и во время выполнения.
    /// </summary>
    public sealed class SampleDataSource
    {
        public static ObservableCollection<SampleDataGroup> _allGroups = new ObservableCollection<SampleDataGroup>();

        public static ObservableCollection<SampleDataGroup> AllGroups
        {
        get{return _allGroups;}
        }

        public static SampleDataGroup GetGroup(string uniqueId)
        {
            var matches = AllGroups.Where((group) => group.UniqueId.Equals(uniqueId));

            if (matches.Count() == 1) return matches.First();
            return null;
        }

        public static SampleDataItem GetItem(string uniqueId)
        {
            var matches = AllGroups.SelectMany(group => group.Items).Where((item)=>item.UniqueId.Equals(uniqueId));

            if (matches.Count() == 1) return matches.First();
            return null;
        }

        public static async Task<bool> AddGroupForFeedAsync(string feedUrl)
        {
            if (SampleDataSource.GetGroup(feedUrl) != null) return false;

            var feedClient = new SyndicationClient();
            var feed = await feedClient.RetrieveFeedAsync(new Uri(feedUrl));

            var feedGroup = new SampleDataGroup(
                uniqueId: feedUrl,
                title: feed.Title != null ? feed.Title.Text : null,
                subtitle: feed.Subtitle != null ? feed.Subtitle.Text : null,
                imagePath: feed.ImageUri != null ? feed.ImageUri.ToString() : null,
                description: null);

            foreach (var i in feed.Items)
            {
                string imgPath = GetImageFromPostContenst(i);
                if (imgPath != null && feedGroup.ImagePath == null)
                    feedGroup.ImagePath = imgPath;

                var dataItem = new SampleDataItem(
                uniqueId: i.Id,
                title: i.Title.Text,
                subtitle: null,
                imagePath: imgPath,
                description: null,
                content: i.Summary.Text);

                feedGroup.Items.Add(dataItem);
            }            

            AllGroups.Add(feedGroup);

            return true;
        }

        public static string GetImageFromPostContenst(SyndicationItem item)
        {
            var regex = new Regex("[src href]]]s*(?:\"(?<1>[^\"]*)\"|(?<1>\\S+))");

            var matches = regex.Matches(item.Summary.Text);

            return matches.Cast<Match>().Where(
                m =>
                {
                    Uri url;
                    if (Uri.TryCreate(m.Groups[1].Value, UriKind.Absolute, out url))
                    {
                        string ext = Path.GetExtension(url.AbsolutePath).ToLower();
                        if (ext == ".png" || ext == ".jpg" || ext == ".jpeg") return true;
                    }
                    return false;
                }
                )
                .Select(m => m.Groups[1].Value).FirstOrDefault(); 
        }
    }
}