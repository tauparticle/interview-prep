/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        int charCount[26] = {0};
        
        for (char c : s)
        {
            charCount[c - 'a']++;
        }
        
        for (int i=0; i<s.length(); ++i)
        {
            if (charCount[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
