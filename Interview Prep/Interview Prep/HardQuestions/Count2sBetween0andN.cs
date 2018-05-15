using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class Count2sBetween0andN
    {

        public static void Test()
        {
            Console.WriteLine("2s in 1234522 = " + numberOf2sInRangeBruteForce(1234522));
            Console.WriteLine("2s in 102 = " + numberOf2sInRangeBruteForce(102));
            Console.WriteLine("2s in 100 = " + numberOf2sInRangeBruteForce(100));
            Console.WriteLine("2s in 2 = " + numberOf2sInRangeBruteForce(2));
            Console.WriteLine("2s in 222 = " + numberOf2sInRangeBruteForce(222));
        }

        public static int numberOf2sInRangeBruteForce(int n)
        {

            int count = 0;
            for (int i = 2; i <= n; ++i)
            {
                count += numberOf2s(i);
            }
            return count;
        }

        public static int numberOf2s(int n)
        {
            int count = 0;
            while (n > 0)
            {
                if (n % 10 == 2)
                {
                    count++;
                }
                n = n / 10;
            }

            return count;
        }
    }

   
}
