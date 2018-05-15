using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class FindAllRepeatingSubstrings
    {
        public static void Test()
        {
            PrintRepeatedSubStrings("ABABC", 2);
            PrintRepeatedSubStrings("ABABBABBZEDZEDZE", 3);
            PrintRepeatedSubStrings("AAGATCCGTCCCCCCAAGATCCGTC", 10);
        }

        public static void PrintRepeatedSubStrings(string input, int subLength)
        {
            if (string.IsNullOrEmpty(input) || subLength > input.Length)
            {
                Console.WriteLine("Invalid args");
            }
            
            int i = 0;
            int j = i + subLength;
            HashSet<String> tempSet = new HashSet<string>();
            List<string> repeatingSequences = new List<string>();
            while (j <= input.Length)
            {
                string substr = input.Substring(i, j - i);
                if (!tempSet.Add(substr))
                {
                    repeatingSequences.Add(substr);
                }
                i++;
                j = i + subLength;
            }

            repeatingSequences.Sort();

            foreach (string str in repeatingSequences)
            {
                Console.WriteLine(str);
            }

            
        }
    }
}
