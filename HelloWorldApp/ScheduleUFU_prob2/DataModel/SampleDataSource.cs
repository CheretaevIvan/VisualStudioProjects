using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using Windows.Data.Json;
using Windows.Storage;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.Web.Http;
using Windows.Web.Syndication;
using HtmlAgilityPack;

// Модель данных, определяемая этим файлом, служит типичным примером строго типизированной
// по умолчанию.  Имена свойств совпадают с привязками данных из стандартных шаблонов элементов.
//
// Приложения могут использовать эту модель в качестве начальной точки и добавлять к ней дополнительные элементы или полностью удалить и
// заменить ее другой моделью, соответствующей их потребностям. Использование этой модели позволяет повысить качество приложения 
// скорость реагирования, инициируя задачу загрузки данных в коде программной части для App.xaml, если приложение 
// запускается впервые.

namespace ScheduleUFU_prob2.Data
{
    /// <summary>
    /// Универсальная модель данных элементов.
    /// </summary>
    public class SampleDataItem
    {
        public SampleDataItem(String uniqueId, String title, String subtitle, String imagePath, String description, List<Class> content)
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
        public List<Class> Content { get; private set; }

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
        public string ImagePath { get; private set; }
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
            get { return _allGroups; }
        }

        public static SampleDataGroup GetGroup(string uniqueId)
        {
            var matches = AllGroups.Where((group) => group.UniqueId.Equals(uniqueId));

            if (matches.Count() == 1) return matches.First();
            return null;
        }

        public static SampleDataItem GetItem(string uniqueId)
        {
            var matches = AllGroups.SelectMany(group => group.Items).Where((item) => item.UniqueId.Equals(uniqueId));

            if (matches.Count() == 1) return matches.First();
            return null;
        }

        public static async Task<bool> AddGroupForFeedAsync(string feedUrl)
        {
            if (SampleDataSource.GetGroup(feedUrl) != null) return false;

            string mainUrl = "http://urfu.ru/";
            string toSchedule = "student/schedule/schedule/list/institute/";
            string getInstitutes = "student/schedule/schedule/list/group/institute";
            string getGroups = "student/schedule/schedule/list/lesson/institute";
            var webGet = new HtmlAgilityPack.HtmlWeb();
            var doc = await webGet.LoadFromWebAsync(mainUrl + toSchedule);
            var listInstituts = doc.DocumentNode.Descendants("a").Where(item => item.Attributes["href"].Value.StartsWith(getInstitutes));

            var feedGroup = new SampleDataGroup(
                uniqueId: mainUrl + listInstituts.Skip(7).First().Attributes["href"].Value,
                title: listInstituts.Skip(7).First().InnerHtml,
                subtitle: null,
                imagePath: "C:/Users/Иван/documents/visual studio 2013/Projects/HelloWorldApp/RssApp/Assets/SmallLogo.scale-100.png",
                description: null);
            var institut = listInstituts.Skip(7).First();
            {
                doc = await webGet.LoadFromWebAsync(mainUrl + institut.Attributes["href"].Value);
                var listGroups = doc.DocumentNode.Descendants("a").Where(item => item.Attributes["href"].Value.StartsWith(getGroups));
                foreach (var group in listGroups)
                {
                    doc = await webGet.LoadFromWebAsync(mainUrl + group.Attributes["href"].Value);
                    var schedule = doc.DocumentNode.Descendants("table");//.Where(item => item.Attributes["class"])
                    var i = new Schedule(schedule);
                    var dataItem = new SampleDataItem(
                        uniqueId: mainUrl + group.Attributes["href"].Value,
                        title: group.InnerHtml,
                        subtitle: "Расписание",
                        imagePath: "C:/Users/Иван/documents/visual studio 2013/Projects/HelloWorldApp/RssApp/Assets/SmallLogo.scale-100.png",
                        description: null,
                        content: i.evenweekclass);
                    feedGroup.Items.Add(dataItem);

                }
            }

            AllGroups.Add(feedGroup);

            return true;
        }    
    }
}

class Schedule
{
    public List<Classes> evenweek;
    public List<Class> evenweekclass;
    public List<Classes> notevenweek;
    public Schedule(IEnumerable<HtmlNode> days)
    {
        evenweek = new List<Classes>();
        foreach (var day in days)
        {
            evenweek.Add(new Classes(day));
        }
        foreach (var day in evenweek)
        {
            foreach (var pair in day.listClasses)
                evenweekclass.Add(pair);
        }
        
    }
}

class Classes
{
    public List<Class> listClasses { get; set; }
    public Classes(HtmlNode day)
    {
        listClasses = new List<Class>();
        var pairs = day.Descendants().Where(item => item.Name == "tr");
        foreach (var pair in pairs)
        {
            this.listClasses.Add(new Class(pair));
        }
    }
}

public class Default
{
    public static string number = "1";
    public static string subject = "";
    public static string type = "";
    public static string teacher = "";
    public static string auditorium = "";
}
class Class
{
    public string NumberClass { get; set; }
    public string Subject { get; set; }
    public string Type { get; set; }
    public string Teacher { get; set; }
    public string Auditorium { get; set; }
    public override string ToString()
    {
        return String.Format("{0} {1} {2} {3} {4} ", this.NumberClass, this.Subject, this.Type, this.Teacher, this.Auditorium);
    }
    public Class(HtmlNode pair)
    {
        try
        {
            this.NumberClass = pair.Descendants("td").Where(itempair => itempair.Attributes["class"].Value.StartsWith("td-npair")).First().InnerHtml.Trim();
            Default.number = this.NumberClass;
        }
        catch (Exception e)
        {
            this.NumberClass = Default.number;
        }
        try
        {
            this.Subject = pair.Descendants("td").Where(itempair => itempair.Attributes["class"].Value.StartsWith("td-sbname")).First().InnerHtml.Trim();
            Default.subject = this.Subject;
        }
        catch (Exception e)
        {
            this.Subject = Default.subject;
        }
        try
        {
            this.Type = pair.Descendants("td").Where(item => item.Attributes["class"].Value.StartsWith("td-type")).First().InnerHtml.Trim();
            Default.type = this.Type;
        }
        catch (Exception e)
        {
            this.Type = Default.type;
        }
        try
        {
            this.Teacher = pair.Descendants("td").Where(item => item.Attributes["class"].Value.StartsWith("td-initials")).First().InnerHtml.Trim();
            Default.teacher = this.Teacher;
        }
        catch
        {
            this.Teacher = Default.teacher;
        }
        try
        {
            this.Auditorium = pair.Descendants("td").Where(item => item.Attributes["class"].Value.StartsWith("td-aname")).First().InnerHtml.Trim();
            Default.auditorium = this.Auditorium;
        }
        catch (Exception e)
        {
            this.Auditorium = Default.auditorium;
        }
    }
}