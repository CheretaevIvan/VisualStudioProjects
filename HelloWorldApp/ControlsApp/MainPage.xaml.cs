using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using HtmlAgilityPack;

// Шаблон элемента пустой страницы задокументирован по адресу http://go.microsoft.com/fwlink/?LinkId=234238

namespace ControlsApp
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private ObservableCollection<PersonGroup> _groups;
        public MainPage()
        {
            this.InitializeComponent();

            _groups = new ObservableCollection<PersonGroup>();


            var rtf = new PersonGroup { GroupName = "РТФ" };
            var designers = new PersonGroup { GroupName = "Дизайнеры" };

            _groups.Add(rtf);
            _groups.Add(designers);

            rtf.Persons.Add(new Person2{
            LastName = "Иванов",
            FirstName = "Иван",
            Age = 18});
            rtf.Persons.Add(new Person{
                FirstName = "Сергей",
                LastName = "Сергеев",
                Age = 16
            });

            designers.Persons.Add(new Person
            {
                LastName = "Иванов",
                FirstName = "Павел",
                Age = 18
            });
            designers.Persons.Add(new Person
            {
                FirstName = "Андрей",
                LastName = "Сергеев",
                Age = 16
            });

            cvsMain.Source = _groups;
        }
    }
}

class Schedule
{
    public List<Classes> evenweek;
    public List<Classes> notevenweek;
    public Schedule(IEnumerable<HtmlNode> days)
    {
        evenweek = new List<Classes>();
        foreach (var day in days)
        {
            evenweek.Add(new Classes(day));
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
        Console.WriteLine(this.ToString());
    }
}
