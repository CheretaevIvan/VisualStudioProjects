using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CiscoInit.Entities
{
    public class Vlan
    {
        public int Id { get; set; }
        public String Name { get; set; }
        public int Number { get; set; }
        public String Description { get; set; }
        public bool IsDown { get; set; }
        public virtual SwitchRouter Switch { get; set; }
        public virtual ICollection<Interface> Interfaces { get; set; }

        public Vlan()
        {
            Name = "native vlan";
            Number = 1;
            Description = "";
            IsDown = true;
            Interfaces = new List<Interface>();
        }

        public Vlan(String name, int number, bool isDown = true, String description = "")
        {
            Name = name;
            Number = number;
            IsDown = isDown;
            Description = description;
            Interfaces = new List<Interface>();
        }
    }
}
