using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public class SumOfMaxRunningSequence
    {
        public static void Test()
        {
            int[] n = new int[] {2, 3, -1, 4, 2, -9};
            Console.WriteLine("Longest sequence sum = " + GetMaxSum(n));

            List<int> sequence;
            int sum = GetMaxSumWithSequence(n, out sequence);
            Console.Write("Longest sequence sum = " + GetMaxSum(n) + " Seq = ");
            foreach (var i in sequence)
            {
                Console.Write(i<0 ? "(" + i +")" : i + "->");
            }
        }


        public static int GetMaxSumWithSequence(int[] n, out List<int> sequence)
        {
            int maxSum = 0;
            int currentSum = 0;
            sequence = null;
            List<int> currentSequence = new List<int>();
            for (int i = 0; i < n.Length; ++i)
            {
                currentSequence.Add(n[i]);
                currentSum += n[i];
                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                    sequence = new List<int>(currentSequence);
                }
                else if (currentSum < 0)
                {
                    currentSum = 0;
                    currentSequence.Clear();
                }
            }

            return maxSum;
        }

        public static int GetMaxSum(int[] n)
        {
            int maxSum = 0;
            int currentSum = 0;
            for (int i = 0; i < n.Length; ++i)
            {
                currentSum += n[i];
                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                }
                else if (currentSum < 0)
                {
                    currentSum = 0;
                }
            }

            return maxSum;
        }
    }
}
