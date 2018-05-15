/* Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
 
 For example:
 
 Given "aacecaaa", return "aaacecaaa".
 
 Given "abcd", return "dcbabcd".
 
 Credits:
 Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.
 
 Hide Company Tags Pocket Gems Google
 Hide Tags String
 Hide Similar Problems (M) Longest Palindromic Substring (E) Implement strStr() (H) Palindrome Pairs
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        
        int len = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int i=len;
        for (; i >= 0; i--)
        {
            string s_sub = s.substr(0, i);
            string rev_sub = rev.substr(len-i);
            if (s_sub == rev_sub)
            {
                break;
            }
        }
        
        for(int c=len-i-1; c >= 0; c--)
        {
            s = rev[c] + s;
        }
        return s;
        
        
    }
    
};
