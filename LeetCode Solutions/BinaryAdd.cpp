/*
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
 */

class Solution {
public:
    string addBinary(string a, string b) {
        ostringstream s;
        int i=a.length()-1;
        int j=b.length()-1;
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            sum(a[i], b[j], carry, s);
            i--; j--;
        }
        
        while (i >=0)
        {
            sum(a[i], '0', carry, s);
            i--;
        }
        
        while (j >= 0)
        {
            sum('0', b[j], carry, s);
            j--;
        }
        
        if (carry == 1)
        {
            s << "1";
        }
        
        string str = s.str();
        reverse(str.begin(), str.end());
        return str;
    }
    
private:
    
    void sum(char a, char b, int& carry, ostringstream& s)
    {
        int ai = a == '0' ? 0 : 1;
        int bj = b == '0' ? 0 : 1;
        
        int sum = ai + bj + carry;
        switch (sum)
        {
            case 0:
                s << "0";
                carry = 0;
                break;
            case 1:
                s << "1";
                carry = 0;
                break;
            case 2:
                s << "0";
                carry = 1;
                break;
            case 3:
                s << "1";
                carry = 1;
                break;
        }
    }
};