using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InitRouter.Entities
{
    public class SwitchRouter
    {
        public IList<Interface> Interfaces;

        public SwitchRouter()
        {
            Interfaces = new List<Interface>(24);
            for(var i=1;i<=24;i++){
                Interfaces.Add(new Interface("FastEthernet0/", i));
            }
        }

        public SwitchRouter(IList<Interface> interfaces)
        {
            Interfaces = interfaces;
        }
    }
}
