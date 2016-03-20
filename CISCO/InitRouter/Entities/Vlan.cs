using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InitRouter.Entities
{
    public class Vlan
    {
        public String Name { get; set; }
        public int Number { get; set; }
        public String Description { get; set; }
        public bool IsDown { get; set; }

        public Vlan()
        {
            Name = "native vlan";
            Number = 1;
            Description = "";
            IsDown = true;
        }

        public Vlan(String name, int number, bool isDown = true, String description = "")
        {
            Name = name;
            Number = number;
            IsDown = isDown;
            Description = description;
        }
    }
}
