using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;

using InitRouter.Entities;

namespace InitRouter.Database
{
    class CiscoDatabaseContext : DbContext
    {
        public CiscoDatabaseContext()
            : base("CiscoDatabaseConnectionString")
        { }

        public DbSet<SwitchRouter> SwitchRouters { get; set; }
        public DbSet<Interface> Interfaces { get; set; }
        public DbSet<Vlan> Vlans { get; set; }
    }
}
