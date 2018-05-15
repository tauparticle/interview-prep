using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class RansomNote
    {
        public static void Test()
        {
            // note = "my dog" materials="the mystery of the bog is dead" (true)
            // note = "my dog" materials = "empty" (false)
            // note = null/string.empty (true)
            // note = "foo" materials = null/empty (false)
            // note = "my dog" materials = "rubber baby buggy bumper" (false)

            Console.WriteLine("my dog vs the mystery of the bog is dead = " + CanMakeRansomNote("my dog", "the mystery of the bog is dead"));
            Console.WriteLine("my dog vs empty = " + CanMakeRansomNote("my dog", "empty"));
            Console.WriteLine("null = " + CanMakeRansomNote(null, "the mystery of the bog is dead"));
            Console.WriteLine("string.empty = " + CanMakeRansomNote(string.Empty, "the mystery of the bog is dead"));
            Console.WriteLine("foo vs the null = " + CanMakeRansomNote("foo", null));
            Console.WriteLine("foo vs the null = " + CanMakeRansomNote("foo", string.Empty));
            Console.WriteLine("my dog vs ruber baby buggy bumper = " + CanMakeRansomNote("my dog", "rubber baby buggy bumper"));

        
        }

        /// <summary>
        /// note size = n, materials size = m
        /// best case scenario O(1)
        /// worst case scenario O(m)
        /// </summary>
        /// <param name="note"></param>
        /// <param name="materials"></param>
        /// <returns></returns>
        public static bool CanMakeRansomNote(string note, string materials)
        {
            if (materials == null) return false;
            if (string.IsNullOrEmpty(note)) return true;  // no ransom note to make
            if (note.Length > materials.Length) return false;  // insufficient materials

            // categorize the number of characters we need for the note.  // use large enough array or a map
            Dictionary<char, uint> dict = new Dictionary<char, uint>();
            int totalUniqueChars = 0;

            foreach (char c in note)
            {
                if (c == ' ')
                {
                    continue;
                }
                if (dict.ContainsKey(c))
                {
                    dict[c]++;
                    continue;
                }

                // want to track the number of unique keys we have
                dict[c] = 1;
                totalUniqueChars++;
            }

            // iterate through materials
            // --> if we find a char match, decrement the character count from our  map
            // --> if total char count needed == zero, return success
            foreach (char c in materials)
            {
                if (c == ' ')
                {
                    continue;
                }

                if (dict.ContainsKey(c))
                {
                    dict[c]--;
                    if (dict[c] == 0)
                    {
                        totalUniqueChars--;
                    }
                }

                if (totalUniqueChars == 0)
                {
                    return true;
                }                    
            }

            return false;
        }
    }
}
