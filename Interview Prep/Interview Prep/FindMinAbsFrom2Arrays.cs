using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class FindMinAbsFrom2Arrays
    {
        // Assumes sorted O(n).  
        public static int FindMinAbsValue(int[] a, int[] b)
        {
            int minAbs = int.MaxValue;
            int i = 0;
            int j = 0;
            while (i < a.Length && j < b.Length)
            {
                if (a[i] <= b[j])
                {
                    minAbs = Math.Min(minAbs, b[j] - a[i++]);
                }
                else
                {
                    minAbs = Math.Min(minAbs, a[i] - b[j++]);
                }
            }

            return minAbs;
        }

        public static void Test()
        {
            int[] a = new int[] { 1, 3, 5, 7, 9, 11 };
            int[] b = new int[] { 2, 6, 10, 12, 13, 14 };
            Console.WriteLine("minimum abs value in arrays is = " + FindMinAbsValue(a, b));

        }
    }
}
