/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 
 Hide Company Tags Amazon Microsoft Bloomberg
 Hide Tags String
 Hide Similar Problems (H) Shortest Palindrome (E) Palindrome Permutation (H) Palindrome Pairs

 */

class Solution {
public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end-start + 1);
    }
    
    int expandAroundCenter(string& s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};