/*
 Validate if a given string is numeric.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 */

class Solution {
public:
    bool isNumber(string s) {
        
        int i=0;
        int len = s.length();
        
        // handle leading zeros
        while (i < len && isspace(s[i])) i++;
        
        // handle sign
        if (i < len && (s[i] == '+' || s[i] == '-')) i++;
        
        // handing leading numeric
        bool isNumeric = false;
        while (i < len && isdigit(s[i]))
        {
            i++;
            isNumeric = true;
        }
        
        // handle dot delim
        if (i<len && s[i] == '.')
        {
            i++;
            while (i < len && isdigit(s[i]))
            {
                i++;
                isNumeric = true;
            }
        }
        
        // handle exponent case
        if (isNumeric && i < len && (s[i] == 'e' || s[i] == 'E'))
        {
            // following 'e', the only legal values are +,-,0-9
            i++;
            isNumeric = false;
            if (i < len && (s[i] == '+' || s[i] == '-')) i++;
            while (i < len && isdigit(s[i]))
            {
                i++;
                isNumeric = true;
            }
        }
        
        // trailing whitespace
        while (i < len && isspace(s[i])) i++;
        
        return (isNumeric && i == len);
        
    }
};