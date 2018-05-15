/*
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 */

class Solution {
public:
    int titleToNumber(string s)
    {
        int number = 0, len = s.length();
        for(int i = 0, p = len - 1; i < len; ++i, --p)
        {
            char letter = s[i];
            int val = letter - 'A';
            number += (val+1) * pow(26, p);
        }
        return number;
    }
};

