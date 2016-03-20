using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InitRouter.Entities
{
    public class Interface
    {
        public int Number { get; set; }
        public String Type { get; set; }

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
