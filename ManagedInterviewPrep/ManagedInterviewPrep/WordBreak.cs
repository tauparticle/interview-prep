using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ManagedInterviewPrep
{
    public static class WordBreakHelper
    {
        public static ISet<string> GenerateDictionary()
        {
            // abear
            ISet<string> dict = new HashSet<string>();
            dict.Add("a");
            dict.Add("be");
            dict.Add("bear");
            dict.Add("ear");
            dict.Add("abe");
            dict.Add("ar");
            return dict;
        }

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
        private Dictionary<string, string> cache = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

        public string BreakString(string input, ISet<string> dictionary)
        {
            if (this.cache.ContainsKey(input))
            {
                return this.cache[input];   
            }

            int len = input.Length;
            for (int i = 1; i <= len; ++i)
            {
                string prefix = input.Slice(0, i);//input.Substring(0, i);
                if (dictionary.Contains(prefix))
                {
                    string suffix = input.Slice(i, len);//input.Substring(i, len);
                    string segSuffix = this.BreakString(suffix, dictionary);
                    if (segSuffix != null)
                    {
                        string result = string.Concat(prefix, " ", segSuffix);
                        this.cache[input] = result;
                        return result;
                    }
                }
            }

            this.cache[input] = null;
            return null;
        }
    }   
}

/*
Map<String, String> memoized;

String SegmentString(String input, Set<String> dict) {
  if (dict.contains(input)) return input;
  if (memoized.containsKey(input) {
    return memoized.get(input);
  }
  int len = input.length();
  for (int i = 1; i < len; i++) {
    String prefix = input.substring(0, i);
    if (dict.contains(prefix)) {
      String suffix = input.substring(i, len);
      String segSuffix = SegmentString(suffix, dict);
      if (segSuffix != null) {
        memoized.put(input, prefix + " " + segSuffix);
        return prefix + " " + segSuffix;
      }
    }
    memoized.put(input, null);
    return null;
}
*/