using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    public static class FindFirstNonRepeatingChar
    {
        public static void Test()
        {
            Console.WriteLine("First NonRepeating Char in adfaeadffewdsdfss is {0}", FirstNonRepeatingCharacter("adfaeadffewdsdfss"));
            Console.WriteLine("First NonRepeating Char in aaaaaaaabccc is {0}", FirstNonRepeatingCharacter("aaaaaaaabccc"));
            Console.WriteLine("First NonRepeating Char in ababcededecf is {0}", FirstNonRepeatingCharacter("ababcededecf"));
            Console.WriteLine("First NonRepeating Char in xap is {0}", FirstNonRepeatingCharacter("xap"));
        }

        public class CharInfo
        {
            public int count;
            public int firstIndex;

            public CharInfo()
            {
                this.count = 0;
                this.firstIndex = -1;
            }
        }

        public static char FirstNonRepeatingCharacter(string input)
        {
            // O(n) because we go through n chars and then once more through the charMap to find the first non-repeating
            CharInfo[] charMap = new CharInfo[256];
            for (int i = 0; i < charMap.Length; ++i)
            {
                charMap[i] = new CharInfo();
            }

            for (int i = 0; i < input.Length; ++i)
            {
                CharInfo ci = charMap[input[i]];
                if (ci.count == 0)
                {
                    ci.firstIndex = i;
                }
                ci.count++;
            }

            int firstNonRepeatingCharIndex = int.MaxValue;
            for (int i = 0; i < charMap.Length; ++i)
            {
                if (charMap[i].count == 1)
                {
                    firstNonRepeatingCharIndex = Math.Min(firstNonRepeatingCharIndex, charMap[i].firstIndex);
                }
            }

            return (firstNonRepeatingCharIndex < input.Length) ? input[firstNonRepeatingCharIndex] : '\0';
        }
    }
}
