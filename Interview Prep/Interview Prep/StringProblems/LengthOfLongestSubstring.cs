using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.StringProblems
{
    public static class LengthOfLongestSubstringProblem
    {
        public static void Test()
        {
            Console.WriteLine("abcabcbb = {0}", lengthOfLongestSubstring("abcabcbb"));
            Console.WriteLine("bbbbbbbb = {0}", lengthOfLongestSubstring("bbbbbbbb"));
        }

        /// <summary>
        /// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without 
        /// repeating letters for “abcabcbb” is “abc”, which the length is 3. For “bbbbb” the longest substring is “b”, with the length of 1.
        /// </summary>
        /// <remarks>O(n) complexity with O(1) constant space</remarks>
        /*
         * When you have found a repeated character (let’s say at index j), it means that the current substring (excluding the repeated character of course) 
         * is a potential maximum, so update the maximum if necessary. It also means that the repeated character must have appeared before at an index i, 
         * where i is less than j.
         * Since you know that all substrings that start before or at index i would be less than your current maximum, you can safely start to look for the 
         * next substring with head which starts exactly at index i+1.
         * Therefore, you would need two indices to record the head and the tail of the current substring. Since i and j both traverse at most n steps, 
         * the worst case would be 2n steps, which the run time complexity must be O(n).*/
        public static int lengthOfLongestSubstring(string s)
        {
            int n = s.Length;
            int tail = 0, head = 0;
            int maxLen = 0;
            bool[] exist = new bool[256];
            while (head < n)
            {
                if (exist[s[head]])
                {
                    maxLen = Math.Max(maxLen, head - tail);
                    while (s[tail] != s[head])
                    {
                        exist[s[tail]] = false;
                        tail++;
                    }
                    tail++;
                    head++;
                }
                else
                {
                    exist[s[head]] = true;
                    head++;
                }
            }
            maxLen = Math.Max(maxLen, n - tail);
            return maxLen;
        }
    }
}
