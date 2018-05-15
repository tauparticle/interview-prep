using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class Combinations
    {
        public static void Test()
        {
            var list = ComputeCombinations("abcd");
            Console.WriteLine("Total Combos : " + list.Count);
            foreach (string s in list)
            {
                Console.WriteLine(s);
            }
        }

        /// 2^n (cannot do better)
        public static IList<string> ComputeCombinations(string input)
        {
            if (input == null) return null;

            // find the max number of combos (2^n)
            int maxNumber = 1 << input.Length;

            List<string> combos = new List<string>();
            StringBuilder sb = new StringBuilder();

            // iterate through each unique number
            for (int i = 0; i < maxNumber; ++i)
            {
                // produce a subsequence of elements by aligning the indexes with the binary "1's" in the number
                string subSeq = combineCharsWithBinaryOnes(input, i, sb);
                // add the subsequence to our list
                combos.Add(subSeq);
            }

            // return the list
            return combos;
        }

        private static string combineCharsWithBinaryOnes(string input, int number, StringBuilder sb)
        {
            sb.Clear();
            int index = 0;
            for (int i = number; i > 0; i >>= 1)
            {
                if ((i & 1) == 1)
                {
                    sb.Append(input[index]);
                }
                index++;
            }

            return sb.ToString();
        }
    }
}
