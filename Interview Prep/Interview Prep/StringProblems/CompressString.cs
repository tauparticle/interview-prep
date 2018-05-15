using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class CompressString
    {
        
        public static void Test()
        {
            // input abccccccd = ab_5cd
            // input abccdddee = abcc_3dee
            // input abccddde = abcc_3de
            Console.WriteLine("abccccccd -> " + compress("abccccccd"));
            Console.WriteLine("abccdddee -> " + compress("abccdddee"));
            Console.WriteLine("abccddde -> " + compress("abccddde"));
            Console.WriteLine("abccxxxxxxxxxxxxdddaaaaaaae -> " + compress("abccxxxxxxxxxxxxdddaaaaaaae"));

        }
        
        public static string compress(string input)
        {
            if (string.IsNullOrEmpty(input)) return input;
            if (input.Length < 3) return input;

            StringBuilder sb = new StringBuilder(input.Length);
            int tail = 0;
            int count = 1;
            for (int i = 1; i < input.Length; ++i)
            {
                if (input[i] == input[tail])
                {
                    count++;
                }
                else
                {
                    if (count > 2)
                    {
                        // only if count is greater than 2 will we compress
                        sb.Append("_");
                        sb.Append(count);
                        sb.Append(input[tail]);
                    }
                    else
                    {
                       // otherwise update the tail to i
                        while (tail < i)
                       {
                           sb.Append(input[tail++]);
                       }
                    }
                    
                    tail = i;
                    count = 1;
                }
            }

            sb.Append(input[tail]);

            return (sb.Length > input.Length) ? input : sb.ToString();
        }
    }
}
