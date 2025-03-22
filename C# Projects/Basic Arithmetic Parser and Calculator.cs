using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string ıslem = "10+5-20+10/2+5*5";


            //var ıslem2 = ıslem.ToCharArray();


            char[] Operator = { '+', '-', '*', '/' };

            var sayi = ıslem.Split(Operator);


            //var qwdqwd = sayi;

            //foreach (var a in sayi)
            //{

            //    Console.WriteLine(a);
            //}


            //foreach(var a in sayi)
            //{
            //    Console.WriteLine(a);
            //}

            //char[] Operator2 = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9','\t', '\n' };

            var isaret = Regex.Replace("10+5-20+10/2+5*5", "[0-9,.]", "");




            int l = 0;
            foreach (var a in isaret)
            {

                if (a == '*' || a == '/')
                {
                    l++;
                }

            }

            double[] sayi3 = new double[sayi.Length - l];

            int i = 0;
            int c = 0;
            int k = 0;


            foreach (var a in isaret)
            {


                if (a == '*')
                {
                    sayi3[k] = Convert.ToDouble(sayi[i]) * Convert.ToDouble(sayi[i + 1]);
                    k++;
                    c += 1;

                }
                if (a == '/')
                {
                    sayi3[k] = Convert.ToDouble(sayi[i]) / Convert.ToDouble(sayi[i + 1]);
                    k++;
                    c += 1;
                }

                else if (c < sayi.Length && k < (sayi.Length - l) && isaret[c] != '*' && isaret[c] != '/')
                {
                    sayi3[k] = Convert.ToDouble(sayi[c]);
                    k++;
                }
                i++;
                c++;

            }

            foreach(var s in sayi3)
            {
                Console.WriteLine(s);
            }




            double sonuc = sayi3[0];
            var isaret2 = Regex.Replace("10+5-20+10/2+5*5", "[0-9,*,/,.]", "");

            for (int a = 0; a< isaret2.Length; a++) 
            {
                if(isaret2[a] == '+')
                {
                    sonuc += sayi3[a + 1];
                }
                if (isaret2[a] == '-')
                {
                    sonuc -= sayi3[a + 1];
                }

            }

            Console.WriteLine(sonuc);


            //int p = 0;
            //foreach (var ds in sayi3)
            //{
            //    if (ds == 0)
            //    {
            //        sayi3[p] = Convert.ToDouble(sayi[p]);
            //    }
            //    p++;
            //}

            Console.WriteLine("sadsada");






            //foreach(var a in sayi3)
            //{
            //    Console.WriteLine(a);
            //}
            //for(int i =0; i<sayi2.Length; i++)
            //{
            //    if()
            //}

            //int i = 0;
            //foreach(var a in ıslem2)
            //{

            //    if(a == '*')
            //    {

            //    }
            //}






            Console.ReadKey();

        }
    }
}
