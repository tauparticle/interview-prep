


class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        return (num&0x55555555)&&(num&(num-1))==0;
    }
};


// O(log4 n)
bool isPowerOfFour(int num) {
 
 if (num < 0) return false;
 while (num % 4 == 0)
 {
 num /= 4;
 }
 
 return num == 1;
}

// O(1)
bool isPowerOfFour(int num)
{
    int count = 0;
    int loop = 0;
    while (num > 0)
    {
        count+=(num&0x01);
        loop++;
        num>>=1;
    }
    return count==1 && loop%2==1;
}