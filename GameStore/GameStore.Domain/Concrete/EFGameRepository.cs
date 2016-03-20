using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GameStore.Domain.Abstract;
using GameStore.Domain.Entities;

namespace GameStore.Domain.Concrete
{
    public class EFGameRepository: IGameRepository
    {
        //EFDbContext context = new EFDbContext();

        public IEnumerable<Subject> Subjects
        {
            get //{ return context.Subjects; }
            {
                return new List<Subject> { new Subject { Name = "Subject1", Mark = "отлично", Points = 100 },
            new Subject { Name = "Subject1", Mark = "отлично", Points = 100 }};
            }
        }
    }
}
