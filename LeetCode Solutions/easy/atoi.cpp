class Solution {
public:
    int myAtoi(string str) {
        
        int num = 0;
        int sign = 1;
        int cur = 0;
        int len = str.length();
        
        int maxIntDiv10 = INT_MAX / 10;
        
        // leading space
        while (cur < len && isspace(str[cur])) cur++;
        
        // +/- sign
        if (cur < len && str[cur] == '+') cur++;
        else if (cur < len && str[cur] == '-')
        {
            sign = -sign;
            cur++;
        }
        
        // numeric part
        while (cur < len && isdigit(str[cur]))
        {
            int digit = str[cur] - '0';
            if (num > maxIntDiv10 || (num == maxIntDiv10 && digit >= 8))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num *= 10;
            num += digit;
            cur++;
        }
        
        return num * sign;
    }
};