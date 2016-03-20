using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameStore.Domain.Entities
{
    public class Subject
    {
        public int SubjectId { get; set; }
        public string Name { get; set; }
        public string Semestr { get; set; }
        public string Year { get; set; }
        public string Student { get; set; }
        public double Points { get; set; }
        public string Mark { get; set; }
        public IDictionary<string, Section> Sections { get; set; }

        public Subject()
        {
            Sections = new Dictionary<string, Section>();
        }

        public override string ToString()
        {
            string result = "";
            result += String.Format("Предмет: {0}\nСеместр: {1}\nГод: {2}\nИтоговый балл: {3}\nОценка: {4}\nРазделы:\n", Name, Semestr, Year, Points, Mark);
            foreach (Section section in Sections.Values)
            {
                result += String.Format("\t{0}\n\t\tКоэффициет раздела: {1}\n", section.Name, section.Coef);
                if (section.Exam!=null) result += String.Format("\t\t{0}({1})\n\t\t{2}/{3}\n", section.Exam.Name, section.ExamCoef, section.Exam.Points, section.Exam.Max);
                result += "\t\tРаботы:\n";
               
                foreach (Work work in section.Works)
                {
                    result += String.Format("\t\t\t{0} {1}/{2}", work.Name, work.Points, work.Max);
                }
            }
            return result;
        }
    }
}
