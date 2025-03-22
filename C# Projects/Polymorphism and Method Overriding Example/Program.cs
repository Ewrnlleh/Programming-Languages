using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            Nokta yeniNokta = new Nokta();
            yeniNokta.EY();

            Daire d = new Daire(5);
            d.EY();
        }
    }
}
