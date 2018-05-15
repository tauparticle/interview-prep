using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    public static class DistanceBetweenWordsInASentence
    {
        public static void Test()
        {
            Console.WriteLine();
            Console.WriteLine("Min distance of '{0}' and '{1}' in '{2}' is '{3}'", "hello", "you", "hello how are you", GetDistance("hello how are you", "hello", "you"));
            Console.WriteLine("Min distance of '{0}' and '{1}' in '{2}' is '{3}'", "hello", "you", "hello how are me", GetDistance("hello how are me", "hello", "you"));
            Console.WriteLine("Min distance of '{0}' and '{1}' in '{2}' is '{3}'", "hello", "are", "hello how are you", GetDistance("hello how are you", "hello", "are"));
            Console.WriteLine("Min distance of '{0}' and '{1}' in '{2}' is '{3}'", "hello", "how", "hello how are you", GetDistance("hello how are you", "hello", "how"));
            Console.WriteLine("Min distance of '{0}' and '{1}' in '{2}' is '{3}'", "hello", "hello", "hello how are you", GetDistance("hello how are you", "hello", "hello"));
        }

        /// <summary>
        ///  Returns the minimum distance between two words in a sentence.  Order must be preserved
        /// </summary>
        /// <remarks>O(n) runtime O(n) space due to string parsing</remarks>
        public static int GetDistance(string sentence, string word1, string word2)
        {
            if (string.IsNullOrEmpty(sentence) || string.IsNullOrEmpty(word1) || string.IsNullOrEmpty(word2))
            {
                return -1;
            }

            if (word1.Equals(word2, StringComparison.OrdinalIgnoreCase))
            {
                return 0;
            }

            // for a more optimized solution that doesn't use string creation, we can iterate each char and trap indicies for words
            string[] split = sentence.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
            int minDistance = int.MaxValue;
            int distance = int.MaxValue;
            for (int i = 0; i < split.Length; ++i)
            {
                if (split[i].Equals(word1, StringComparison.OrdinalIgnoreCase))
                {
                    distance = 0;
                }
                else if (split[i].Equals(word2, StringComparison.OrdinalIgnoreCase))
                {
                    minDistance = Math.Min(distance, minDistance);
                }
                distance++;
            }

            if (minDistance > split.Length)
            {
                return -1;
            }
            return minDistance;
        }
    }
}
