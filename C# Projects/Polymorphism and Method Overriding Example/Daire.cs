using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Daire
    {
        private double yariCap;

        public Daire(double yariCap)
        {
            this.yariCap = yariCap;
        }

        private double AlanHesapla()
        {
            return Math.PI * yariCap * yariCap;


        }

        public void EY()
        {
            Console.WriteLine("Alan:" + AlanHesapla());
        }
    }
}
