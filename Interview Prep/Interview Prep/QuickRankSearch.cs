using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class QuickRankSearch
    {

        public static int randomInt(int n)
        {
            Random rand = new Random();
            return (int)(rand.NextDouble() * n);
        }

        public static int randomIntInRange(int min, int max)
        {
            return randomInt(max + 1 - min) + min;
        }

        public static int QuickSelect(int[] a, int len, int k)
        {
            if (a.Length == 1)
            {
                return a[0];
            }

            int randomIndex = randomIntInRange(1, len);
            int pivot = a[randomIndex];
            
            // split into a pile A1 of small element and A2 of big elements
            int[] a1 = new int[len];
            int[] a2 = new int[len];
            int a1End = 0;
            int a2End = 0;
            for (int i = 0; i < len; ++i)
            {
                if (a[i] < pivot)
                {
                    a1[a1End++] = a[i];
                }
                else if (a[i] > pivot)
                {
                    a2[a2End++] = a[i];
                }
            }

            if (k == a1End)
            {
                return pivot;
            }
            
            if (k < a1End)
            {
                // it's in the pile of small elements
                return QuickSelect(a1, a1End, k);
            }

            // it's in the pile of right elements.  Adjust k to fit associated rank of large pile
            return QuickSelect(a2, a2End, k - len - a2End);
        }

        public static void Test()
        {
            Random rand = new Random();
            int[] a = new int[10] {9, 2, 6, 8, 1, 3, 4, 5, 0, 7};
            

            Console.WriteLine("");
            for (int i = 0; i < a.Length; ++i)
            {
                int k = QuickSelect(a, a.Length-1, i);
                Console.WriteLine(i + "th = " + k);
            }

        }
    }
}
