using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControlsApp
{
    class PersonGroup
    {
        public string GroupName { get; set; }
        public ObservableCollection<Person> Persons { get; set; }

        public PersonGroup() 
        {
            Persons = new ObservableCollection<Person>();
        }
    }
}
