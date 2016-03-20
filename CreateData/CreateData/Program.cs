using System;
using System.Globalization;
using System.IO;


namespace CreateData
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter file = new StreamWriter(File.OpenWrite("data.dat"));
            NumberFormatInfo nfi = new NumberFormatInfo();
            nfi.CurrencyDecimalSeparator = ".";
            string someString = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            for (int i=0;i<1000000;i++){
                int i2 = i%10000;
                string row = String.Format("{0};{1};{2};{3};{4}{5};{6}{7};{8};{9};{10};{11}",
                    i, i2, i, i2, someString, i, someString, i2, DateTime.Today.AddSeconds(i).ToString("yyyy-MM-dd hh:mm:ss"), DateTime.Today.AddSeconds(i2).ToString("yyyy-MM-dd hh:mm:ss"), (((double)i) / 10000).ToString(nfi), (((double)i2) / 10000).ToString(nfi));
                file.WriteLine(row);
            }
            file.Close();            
        }
    }
}
