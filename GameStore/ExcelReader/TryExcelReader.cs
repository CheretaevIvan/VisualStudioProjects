using System;
using System.IO;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Excel;
using Excel.Core;
using GameStore.Domain.Entities;

namespace ExcelReader
{
    public class TryExcelReader
    {
        static void Main(string[] args){
            Console.WriteLine(Directory.GetCurrentDirectory().ToString());
            FileStream stream = File.Open("Журнал студента Черетаев И.В.(2014-2015).xls", FileMode.Open, FileAccess.Read);
            IExcelDataReader excelReader = ExcelReaderFactory.CreateBinaryReader(stream);
            DataSet result = excelReader.AsDataSet();

            for (int i = 1; i < result.Tables.Count;i++ )
            {
                Subject subj = parseSubject(result.Tables[i]);
                Console.WriteLine(subj);
            }
            Console.ReadKey();
            excelReader.Close();
        }

        public static IEnumerable<Subject> startParse(Stream file){
            IExcelDataReader excelReader = ExcelReaderFactory.CreateBinaryReader(file);
            DataSet result = excelReader.AsDataSet();
            List<Subject> subjects = new List<Subject>();
            for (int i = 1; i < result.Tables.Count; i++)
            {
                Subject subj = parseSubject(result.Tables[i]);
                subjects.Add(subj);
                //Console.WriteLine(subj);
            }
            excelReader.Close();
            return subjects;
        }

        static Subject parseSubject(DataTable subject)
        {
            string student = (string)subject.Rows[0].ItemArray[0];
            Console.WriteLine(student.Substring(student.IndexOf(' ') +1, student.LastIndexOf(' ') - student.IndexOf(' ') - 2));
            string[] row = ((string)subject.Rows[1].ItemArray[0]).Split('.');
            string subname = row[0];
            string semname = row[1];
            string year = row[2];
            Subject subj = new Subject
            {
                Name = subname,
                Semestr = semname,
                Year = year,
                Student = student
            };
            int i = 0;
            while (true)
            {
                var g = subject.Rows[4].ItemArray[i];

                if (g == null) break;
                string str = (string)g;
                try
                {
                    string name = str.Substring(str.IndexOf('(') + 1, str.IndexOf(')') - str.IndexOf('(') - 1).ToLower();
                    // System.Globalization.CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator = ".";
                    float coef = float.Parse(str.Substring(str.LastIndexOf(' ') + 1), new System.Globalization.CultureInfo("en-US"));
                    //subj.Sections.Add(name, new Section() { Name = name, Coef = coef });
                    Section sect = new Section { Name = name, Coef = coef };
                    subj.Sections[name] = sect;
                    i += 1;
                }
                catch (Exception)
                {
                    break;
                }
            }
            float tmp = 0;
            float.TryParse((string)subject.Rows[5].ItemArray[i], System.Globalization.NumberStyles.Float, new System.Globalization.CultureInfo("en-US"), out tmp);
            subj.Points = tmp;
            if (float.TryParse((string)subject.Rows[5].ItemArray[i + 2], System.Globalization.NumberStyles.Float, new System.Globalization.CultureInfo("en-US"), out tmp))
            {
                i+=2;
                subj.Points = tmp;
            }            
            subj.Mark = (string)subject.Rows[5].ItemArray[i + 1];

            int rowNumber = 8;

            while (rowNumber < subject.Rows.Count && subject.Rows[rowNumber].ItemArray[0] != System.DBNull.Value){
                parseSection(subject, rowNumber, subj.Sections);
                rowNumber += 12;
            }

            return subj;
            //foreach (DataRow row in subject.Rows)

            //{
            //    foreach (var item in row.ItemArray)
            //    {
            //        Console.Write(item + " ");
            //    }
            //    Console.WriteLine();
            //}

        }

        static void parseSection(DataTable subject, int row, IDictionary<string, Section> sections)
        {
            string name = ((string)subject.Rows[row].ItemArray[0]).Split('(')[0].Trim().ToLower();
            if (!sections.Keys.Contains(name))
                sections[name] = new Section { Name = name };
            int column = 0;
            while (true)
            {
                string title = (string)subject.Rows[row + 3].ItemArray[column];
                if (!title.Contains('=')) break;
                string[] tmp = title.Split('=');
                string workName = tmp[0];
                int workMax = int.Parse(tmp[1]);
                float points = 0;
                float.TryParse((string)subject.Rows[row+4].ItemArray[column], System.Globalization.NumberStyles.Float, new System.Globalization.CultureInfo("en-US"), out points);
                sections[name].Works.Add(new Work { Name = workName, Max = workMax, Points = points });
                column++;
            }
            string titleExam = (string)subject.Rows[row + 8].ItemArray[0];
            float coefExam = 0;
            float.TryParse(((string)subject.Rows[row + 8].ItemArray[0]).Split(' ').Last(), System.Globalization.NumberStyles.Float, new System.Globalization.CultureInfo("en-US"), out coefExam);
            if (coefExam != 1.0)
            {
                titleExam = (string)subject.Rows[row + 8].ItemArray[1];
                string[] tmp = titleExam.Split('=');
                string examName = tmp[0];
                int examMax = int.Parse(tmp[1]);
                float points = 0;
                float.TryParse((string)subject.Rows[row + 4].ItemArray[column], System.Globalization.NumberStyles.Float, new System.Globalization.CultureInfo("en-US"), out points);
                sections[name].Exam = new Work { Name = examName, Max = examMax, Points = points };
                sections[name].ExamCoef = 1 - coefExam;
            }
        }
    }
}
