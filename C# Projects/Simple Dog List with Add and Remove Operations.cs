using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{





    class KHJKH
    {


        static void Main()
        {
            List<string> dogs = new List<string>();
            dogs.Add("maltese");    // Contains maltese
            dogs.Add("otterhound"); // maltese, otterhound
            dogs.Add("rottweiler"); // maltese, otterhound, rottweiler
            dogs.Add("bulldog");    // ... rottweiler, bulldog
            dogs.Add("whippet");    // .... rottweiler, bulldog, whippet

            dogs.Remove("bulldog"); // Remove bulldog

            foreach (string dog in dogs)
            {
                Console.WriteLine(dog);
            }
            Console.WriteLine();
            // Contains: maltese, otterhound, rottweiler, whippet

            dogs.RemoveAt(1); // Remove second dog

            foreach (string dog in dogs)
            {
                Console.WriteLine(dog);
            }
            // Contains: maltese, rottweiler, whippet
        }
    }

}
