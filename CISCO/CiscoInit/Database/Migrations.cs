using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CiscoInit.Database
{
    using System.Data.Entity.Migrations;

    internal sealed class Migrations : DbMigrationsConfiguration<CiscoDatabaseContext>
    {
        public Migrations()
        {
            AutomaticMigrationsEnabled = true;
        }

        protected override void Seed(CiscoDatabaseContext context)
        {
        }
    }
}
