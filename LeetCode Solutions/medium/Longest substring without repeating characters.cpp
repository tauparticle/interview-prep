/*3. Longest Substring Without Repeating Characters   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 217171
 Total Submissions: 923585
 Difficulty: Medium
 Contributors: Admin
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
    
    // this is the better path as it comsumes O(1) space and O(2n) time.  However we're limited to ascii
    int lengthOfLongestSubstring(string s) {
        
        bool exists[256] = { false };
        int maxLength = 0;
        int back = 0;
        for (int i=0; i<s.length(); ++i)
        {
            while(exists[s[i]]) {
                exists[s[back]] = false;
                back++;
            }
            
            exists[s[i]] = true;
            maxLength = max(maxLength, i-back+1);
        }
        return maxLength;
        
    }
    
    // for any character set, this impl is more efficient.  But it comes with a cost of O(n) space.
    int lengthOfLongestSubstringUsingSet(string s) {
        
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
