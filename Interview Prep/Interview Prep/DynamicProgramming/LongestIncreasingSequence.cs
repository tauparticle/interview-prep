using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.DynamicProgramming
{
    public static class LongestIncreasingSequenceQuestion
    {

        public static void Test()
        {
            int[] input = {10, 3, 5, 6, 9, 12, 3, 33, 42, 1};
            Console.Write("\nLongestIncreasing Sequence of: ");
            foreach (int i in input) Console.Write(i + ",");
            Console.WriteLine();
            List<int> seq = new List<int>();
            LongestIncreasingSequence(input, seq);
        }

        public static void LongestIncreasingSequence(int[] input, List<int> longestSequence)
        {
            longestSequence.Clear();
            if (input.Length == 0)
            {
                return;
            }

            int[] lis = new int[input.Length];
            int[] previousIndex = new int[input.Length];
            for (int i = 0; i < lis.Length; ++i)
            {
                lis[i] = 1;
                previousIndex[i] = -1;
            }

            int maxLength = 1;
            int longestSequenceEnd = 0;

            for (int i = 1; i < input.Length; ++i)
            {
                int length = 1;
                int prevIndex = -1;
                for (int j = 0; j < i; j++)
                {
                    if (input[j] <= input[i] && lis[j] + 1 > length)
                    {
                        length = lis[j] + 1;
                        prevIndex = j;
                    }
                }

                lis[i] = length;
                previousIndex[i] = prevIndex;

                if (length > maxLength)
                {
                    maxLength = length;
                    longestSequenceEnd = i;
                }
            }

            while (longestSequenceEnd >= 0)
            {
                longestSequence.Add((input[longestSequenceEnd]));
                longestSequenceEnd = previousIndex[longestSequenceEnd];
            }

            longestSequence.Reverse();
        }
    }
}
