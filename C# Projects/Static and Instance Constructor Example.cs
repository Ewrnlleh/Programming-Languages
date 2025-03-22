using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        public Program()
        {
            Console.WriteLine("awdwadwadaw");
        }
        public Program(string b)
        {
            Console.WriteLine(b);
        }

        static Program()
        {
            Console.WriteLine("aaahahaha salak");

        }
        static void Main(string[] args)
        {
            Program a = new Program();
            Program b = new Program("brgnrnrtnrt");
            Program c = new Program("asdasdbrgnrnrtnrt");

        }
    }
}
