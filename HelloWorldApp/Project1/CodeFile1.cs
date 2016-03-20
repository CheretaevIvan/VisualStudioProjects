using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Xml;
using HtmlAgilityPack;

class Program
{
    static void Main ()
    {
        string mainUrl = "http://urfu.ru/";
        string toSchedule = "student/schedule/schedule/list/institute/";
        string getInstitutes = "student/schedule/schedule/list/group/institute";
        string getGroups = "student/schedule/schedule/list/lesson/institute";
        var webGet = new HtmlAgilityPack.HtmlWeb();
        var doc = webGet.Load(mainUrl+toSchedule);
        var listInstituts = doc.DocumentNode.SelectNodes("//a").Where(item => item.Attributes["href"].Value.StartsWith(getInstitutes));
        //foreach (var institut in listInstituts)
        var institut = listInstituts.Skip(7).First();
        {
            Console.WriteLine(institut.InnerHtml);
            doc = webGet.Load(mainUrl + institut.Attributes["href"].Value);
            var listGroups = doc.DocumentNode.SelectNodes("//a").Where(item => item.Attributes["href"].Value.StartsWith(getGroups));
            foreach (var group in listGroups)
            {
                Console.WriteLine(group.InnerHtml);
                doc = webGet.Load(mainUrl + group.Attributes["href"].Value);
                var schedule = doc.DocumentNode.SelectNodes("//table");//.Where(item => item.Attributes["class"])
                new Schedule(schedule);
            }
        }
        //doc = webGet.Load("http://urfu.ru/student/schedule/schedule/list/lesson/institute/6/sch_group/419/week/odd/semi_semester/2/");
        //var schedule = doc.DocumentNode.SelectNodes("//table").Where(item => item.Attributes["class"] != null);
        //new Schedule(schedule);
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
        catch(Exception e)
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
        catch(Exception e)
        {
            this.Auditorium = Default.auditorium;
        }
        Console.WriteLine(this.ToString());
    }
}