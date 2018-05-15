using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class StringHelper
    {
        public static string Slice(this string source, int start, int end)
        {
            if (end < 0) // Keep this for negative end support
            {
                end = source.Length + end;
            }
            int len = end - start;               // Calculate length
            return source.Substring(start, len); // Return Substring of length
        }
    }


    public class WordBreak
    {
        // Worst case O(n^2). Each segment splits twice. 
        Dictionary<string, string> cache = new Dictionary<string, string>(); 
        public string BreakText(string input, ISet<string> dict)
        {
            if (dict.Contains(input)) return input;
            if (this.cache.ContainsKey(input))
            {
                return this.cache[input];
            }

            for (int i = 1; i < input.Length; ++i)
            {
                string prefix = input.Slice(0, i);
                if (dict.Contains(prefix))
                {
                    string suffix = input.Slice(i, input.Length);
                    string segSuffix = this.BreakText(suffix, dict);
                    if (segSuffix != null)
                    {
                        var result = string.Concat(prefix, " ", segSuffix);
                        this.cache[input] = result;
                        return result;
                    }
                }
            }
            return null;
        }
    }

    public static class TestWordBreak
    {
        public static void Run()
        {
            WordBreak wb = new WordBreak();
            var dict = new HashSet<string> {"i", "am", "an", "ice", "cream", "ream", "cone"};
            var result = wb.BreakText("iamanicecreamcone", dict);
            Console.WriteLine("iamanicecreamcone -> " + result);
#pragma warning disable 168
//            Console.ReadKey();
#pragma warning restore 168
        }
    }
}
