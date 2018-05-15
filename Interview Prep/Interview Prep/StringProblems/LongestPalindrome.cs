using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class LongestPalindrome
    {
        public static void Test()
        {
            
            
            Console.WriteLine("James Joyce said tattarrattat in Ulysses=" + longestPalindromeSimple("James Joyce said tattarrattat in Ulysses"));
            Console.WriteLine("Very fast racecar.=" + longestPalindromeSimple("Very fast racecar."));
            Console.WriteLine("a bb aba abba abcba cddc cdc dd c=" + longestPalindromeSimple("a bb aba abba abcba cddc cdc dd c"));
            Console.WriteLine("aba=" + longestPalindromeSimple("aba"));
            Console.WriteLine("abb=" + longestPalindromeSimple("abb"));
            Console.WriteLine("bba=" + longestPalindromeSimple("bba"));
            Console.WriteLine("aa=" + longestPalindromeSimple("aa"));
            Console.WriteLine("ab=" + longestPalindromeSimple("ab"));
            Console.WriteLine("a=" + longestPalindromeSimple("a"));
        }

        public static string expandAroundCenter(string s, int c1, int c2)
        {
            int left = c1;
            int right = c2;
            while (left >= 0 && right <= s.Length - 1 && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.Substring(left + 1, right - left - 1);
        }

        // O(n) average case. O(n^2) if entire string is a palindrome.  
        // fewer palindrome's, the closer to O(n) we run
        public static string longestPalindromeSimple(string s)
        {
            if (s == null) return null;
            if (s.Length == 0) return string.Empty;
            string longest = s.Substring(0, 1);  // a single char itself is a palindrome
            for (int i = 0; i < s.Length - 1; i++)
            {
                // check palindrome centered at s[i]
                string p1 = expandAroundCenter(s, i, i);
                if (p1.Length > longest.Length)
                    longest = p1;
                // check palindrome centered at s[i] and s[i+1] 
                string p2 = expandAroundCenter(s, i, i + 1);
                if (p2.Length > longest.Length)
                    longest = p2;
            }
            return longest;
        }
    }
}
