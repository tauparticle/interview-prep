/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 Hide Company Tags Amazon Adobe Bloomberg Yelp
 Hide Tags Hash Table Two Pointers String
 Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters

 */

class Solution {
public:
    
    // O(n) time.  Space is O(k) where k is the longest substring
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> window;
        int i = 0;
        int j = 0;
        int longest = 0;
        
        while (i < s.length() && j < s.length())
        {
            bool duplicate = window.insert(s[j]).second;
            if (duplicate)
            {
                j++;
                longest = max(longest, j-i);
            }
            else
            {
                window.erase(window.find(s[i]));
                i++;
            }
        }
        
        return longest;
        
    }
};