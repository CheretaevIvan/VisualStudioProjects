using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameStore.Domain.Entities
{
    public class Section
    {
        public string Name { get; set; }
        public float Coef { get; set; }
        public string Teachers { get; set; }
        public IList<Work> Works { get; set; }
        public Work Exam { get; set; }
        public float ExamCoef { get; set; }

        public Section()
        {
            Works = new List<Work>();
        }
    }
}
