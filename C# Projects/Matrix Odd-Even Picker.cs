using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rastgele = new Random();

            int[,] dizi = new int[4, 4];
            int[] tekDizi = new int[8];
            int[] ciftDizi = new int[8];
            int tekSayiAdedi = 0, ciftSayiAdedi = 0;

            for (int i =0; i <4;i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    dizi[i, j] = rastgele.Next(1, 100);
                }
            }


            int x=0,y=0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i % 2 != 0)
                    {
                        tekDizi[x] = dizi[i, j];
                        x++;
                    }
                    if (i % 2 == 0)
                    {
                        ciftDizi[y] = dizi[i, j];
                        y++;
                    }

                }
            }

            Console.Write("Tek Sayılar: ");
            for (int i = 0; i < 8; i++)
            {
                if (ciftDizi[i] % 2 != 0)
                {
                    Console.Write(ciftDizi[i] +" ");
                    tekSayiAdedi++;
                }

            }
            Console.WriteLine();
            Console.WriteLine("Kaç tane:" + tekSayiAdedi);
            Console.WriteLine();


            Console.Write("Cift Sayılar: ");
            for (int i = 0; i < 8; i++)
            {
                if (tekDizi[i] % 2 == 0)
                {
                    Console.Write(tekDizi[i]+" ");
                    ciftSayiAdedi++;
                }

            }
            Console.WriteLine();
            Console.WriteLine("Kaç tane:" + ciftSayiAdedi);
            Console.WriteLine();



        }
    }
}
