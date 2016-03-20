using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CiscoInit.Entities
{
    public class Interface
    {
        public int Id { get; set; }
        public int Number { get; set; }
        public String Type { get; set; }
        public virtual SwitchRouter Switch { get; set; }
        public virtual Vlan NativeVlan { get; set; }

        public Interface()
        {
            Number = 1;
            Type = "FastEthernet0/";
        }

        public Interface(String type, int number)
        {
            Number = number;
            Type = type;
        }
    }
}
