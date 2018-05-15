using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class _3SUM
    {
        public static void Test()
        {
            int[] a = new int[] {5, 3, 8, 2, 9, 8, 1, 0, 2, 3, 1, 1, 3, 2, 4};
            for (int i = 3; i < 20; ++i)
            {
                print3SUM(a, i);
            }
        }

        // O(n^2) Prints each 3 pair of numbers that sum up to a value
        public static void print3SUM(int[] arr, int sum)
        {
            int len = arr.Length;
            if (len < 3) return;  // boof

            // O(n log n)
            Array.Sort(arr);

            // O(n^2)
            for (int i = 0; i < len - 3; ++i)
            {
                int a = arr[i];
                int k = i + 1;
                int l = len - 1;

                while (k < l)
                {
                    int b = arr[k];
                    int c = arr[l];

                    if ((a + b + c) == sum)
                    {
                        Console.WriteLine("{0} + {1} + {2} = {3}", a, b, c, sum);
                        k++;
                        l--;
                    }
                    else if ((a+b+c) > sum)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
    }
}
