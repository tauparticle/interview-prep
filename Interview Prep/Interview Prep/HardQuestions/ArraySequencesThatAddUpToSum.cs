using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.HardQuestions
{
    public static class ArraySequencesThatAddUpToSum
    {
        public static void Tests()
        {
            int[] a = new int[] { 5, 3, 8, 2, 9, 8, 1, 0, 2, 3, 1, 1, 3, 2, 4 };
            for (int i = 11; i < 30; ++i)
            {
                PrintSubsequenSum(a, i);
                //PrintExhaustiveSequenceSum(a, i);
            }
        }

        public static void PrintSubsequenSum(int[] arr, int sum)
        {
            LinkedList<int> backtrace = new LinkedList<int>();
            subset(arr, sum, 0, backtrace, sum);
        }

        public static void printList(LinkedList<int> backtrace, int sum)
        {
            Console.WriteLine("dynamic sum search");
            foreach (var n in backtrace)
            {
                Console.Write("{0}->", n);
            }
            Console.Write("= {0}\n", sum);
        }

        // This is a dynamic programming solutions that's O(n^2), which uses backtracing to print out the results.  It quits after finding a single solution
        public static bool subset(int[] arr, int n, int index, LinkedList<int> backtrace, int originalSum)
        {
            for (int i = index; i < arr.Length; ++i)
            {
                if (n - arr[i] > 0)
                {
                    backtrace.AddLast(arr[i]);
                    if (subset(arr, n - arr[i], i + 1, backtrace, originalSum))
                    {
                        return true;
                    }
                }
                else if (n - arr[i] == 0)
                {
                    backtrace.AddLast(arr[i]);
                    printList(backtrace, originalSum);
                    return true;
                }
            }

            backtrace.RemoveLast();
            return false;
        }


        /// exhaustive approach O(2^n).  Only use this if you need ALL possible results.  Can optimize this with Dynamic programming
        /// to create a hash of the sequences and their sum and cache it.  When a new sequence is created, compute the hash of that sequence and see if a solution exists
        public static void PrintExhaustiveSequenceSum(int[] arr, int sum)
        {
            int maxValue = 1 << arr.Length;

            for (int i = 0; i < maxValue; ++i)
            {
                tryPrintSequenceFromNum(i, arr, sum);

            }
        }

        public static void tryPrintSequenceFromNum(int num, int[] arr, int targetSum)
        {
            int sum = targetSum;
            List<int> sequence = new List<int>();
            int index = 0;
            while (num > 0)
            {
                if ((num & 1) == 1)
                {
                    sequence.Add(arr[index]);
                    sum -= arr[index];

                    if (sum == 0)
                    {
                        print(sequence, targetSum);
                        return;
                    }
                    if (targetSum < 0)
                    {
                        return;
                    }
                }

                num = num >> 1;
                index++;
            }
        }

        public static void print(List<int> sequence, int sum)
        {
            Console.WriteLine("Exhaustive search");
            foreach (var v in sequence)
            {
                Console.Write("{0}->", v);
            }
            Console.WriteLine("={0}", sum);
        }
    }
}
