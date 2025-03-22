using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp9
{
    class Program
    {
        static void Main(string[] args)
        {
            int [,] matrix = new int[,] {{ 1, 2, 4 },{ 5,6,3},{ 2, 5, 6 } };

            int row=3, col=3;

            int i, j;
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < col; j++)
                {
                    if (j < i)
  
                        Console.Write (matrix[i,j] );

                    if (j == i)

                        Console.Write(" ");
                        
                    if (i<j)
                        Console.Write(matrix[i, j] );


                }

                Console.WriteLine();
            }



        }
    }
}
