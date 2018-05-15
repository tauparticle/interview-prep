/*Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 
 For example, Given s = “eceba”,
 
 T is "ece" which its length is 3.
 
 Hide Company Tags Google
 Hide Tags Hash Table Two Pointers String
 Hide Similar Problems (M) Longest Substring Without Repeating Characters (H) Sliding Window Maximum (H) Longest Substring with At Most K Distinct Characters

 
 */

class Solution {
public:
    
    // O(1) space since we're only keeping 2 elements in memory at any given time.
    // O(n) runtime.
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> window;
        
        int tail = 0;
        int head = 0;
        int maxLen = 0;
        while (head < s.length())
        {
            char c = s[head];
            auto iter = window.find(c);
            
            if (iter == window.end())
            {
                // not in the sliding window.  Add it.
                window[c] = 1;
                
                // if window size > 2, pop off the back and increment back
                while (window.size() > 2)
                {
                    char b = s[tail++];
                    window[b]--;
                    if (window[b] == 0)
                    {
                        // remove it
                        window.erase(b);
                    }
                }
            }
            else
            {
                // already in the sliding window
                window[c]++;
            }
            
            head++;
            
            
            maxLen = max(maxLen, head - tail);
        }
        
        return maxLen;
    }
};
