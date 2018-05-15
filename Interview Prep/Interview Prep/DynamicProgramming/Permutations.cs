using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class Permutations
    {
        public static void Test()
        {
            List<string> perms = GeneratePermutation("abcef");
            Console.WriteLine("There are " + perms.Count + " permutations");
            foreach (string s in perms)
            {
                Console.WriteLine(s);
            }       
   
        }

        // abc = a (bc) = bc,cb => abc,bac,bca, acb,cab,cba.  O(n!).  Cannot be done faster
        public static List<string> GeneratePermutation(string input)
        {
           // if input == null, return null
            if (input == null) return null;
            
            List<string> permutations = new List<string>();
            // base case (if input length is zero, return empty list
            if (input.Length == 0)
            {
                permutations.Add("");
                return permutations;
            }

            // get prefix and suffix, and Generate permutations of suffix.
            char prefix = input[0];
            string suffix = input.Substring(1);

            List<string> subPerms = GeneratePermutation(suffix);           

            // foreach suffix entry, combine prefix in each position of the string
            foreach (string sub in subPerms)
            {
                // add that combined string to the return list
                for(int i=0; i<=sub.Length; ++i)
                {
                    string perm = MergePrefixToString(sub, prefix, i);
                    permutations.Add(perm);
                }
            }

            return permutations;       
        }
            
        private static string MergePrefixToString(string str, char c, int index)
        {
            string start = str.Substring(0, index);
            string end = str.Substring(index);
            return start + c + end;
        }
    }
}
