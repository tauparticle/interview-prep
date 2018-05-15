/*  Return true/false if a ransom note can be constructed from a magazine */
 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chars(256, 0);
        
        for (char c : magazine)
        {
            chars[c - '0']++;
        }
        
        for (char c : ransomNote)
        {
            int remaining = chars[c - '0'];
            remaining -= 1;
            if (remaining < 0)
            {
                return false;
            }
            chars[c - '0'] = remaining;
        }
        
        return true;
    }
};