using System.Collections.Generic;
using System.Text;

namespace CiscoInit.Entities
{
    public sealed class SwitchRouter
    {
        private const string DefaultHostname = "S1";
        private const bool DefalutNeededIpDomainLookup = false;
        private const string DefaultEnableSecret = "class";
        private const bool DefaultNeededPasswordEncryption = true;

        private const string DefaultBannerMotd =
            "Laboratory work of \nstudent Cheretaev Ivan group RI320207 \nUnauthorized access to the device ";

        private const bool DefaultNeededLoggingSynchronious = true;
        private const string DefaultUserLoginCon = "cisco";
        private const string DefaultUserPasswordCon = "cisco";
        private const string DefaultUserLoginVty = "cisco";
        private const string DefaultUserPasswordVty = "cisco";

        public SwitchRouter()
        {
            Interfaces = new List<Interface>(24);
            for (var i = 1; i <= 24; i++)
            {
                Interfaces.Add(new Interface("FastEthernet0/", i));
            }
            Hostname = DefaultHostname;
            IsNeedIpDomainLookup = DefalutNeededIpDomainLookup;
            EnableSecret = DefaultEnableSecret;
            IsNeedPasswordEncryption = DefaultNeededPasswordEncryption;
            BannerMotd = DefaultBannerMotd;
            IsNeedLoggingSynchronious = DefaultNeededLoggingSynchronious;
            UserLoginCon = DefaultUserLoginCon;
            UserPasswordCon = DefaultUserPasswordCon;
            UserLoginVty = DefaultUserLoginVty;
            UserPasswordVty = DefaultUserPasswordVty;
        }

        public SwitchRouter(ICollection<Interface> interfaces)
        {
            Interfaces = interfaces;
            Hostname = "S" + Id;
            IsNeedIpDomainLookup = DefalutNeededIpDomainLookup;
            EnableSecret = DefaultEnableSecret;
            IsNeedPasswordEncryption = DefaultNeededPasswordEncryption;
            BannerMotd = DefaultBannerMotd;
            IsNeedLoggingSynchronious = DefaultNeededLoggingSynchronious;
            UserLoginCon = DefaultUserLoginCon;
            UserPasswordCon = DefaultUserPasswordCon;
            UserLoginVty = DefaultUserLoginVty;
            UserPasswordVty = DefaultUserPasswordVty;
        }

        public int Id { get; set; }
        public string Hostname { get; set; }
        public bool IsNeedIpDomainLookup { get; set; }
        public string EnableSecret { get; set; }
        public bool IsNeedPasswordEncryption { get; set; }
        public string BannerMotd { get; set; }
        public bool IsNeedLoggingSynchronious { get; set; }
        public string UserLoginCon { get; set; }
        public string UserPasswordCon { get; set; }
        public string UserLoginVty { get; set; }
        public string UserPasswordVty { get; set; }

        public ICollection<Interface> Interfaces { get; set; }

        public override string ToString()
        {
            var sb = new StringBuilder();
            sb.AppendLine("enable");
            sb.AppendLine("conf t");
            sb.AppendLine("hostname " + Hostname);
            sb.AppendLine((IsNeedIpDomainLookup ? "" : "no") + " ip domain-lookup");
            sb.AppendLine("enable secret " + EnableSecret);
            return sb.ToString();
        }
    }
}