/*Given an integer, write a function to determine if it is a power of three.
Could you do it without using any loop / recursion? */

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if (n == 0) 
        {
            return false;
        }
        
        if (n == 1)
        {
            return true;
        }
        
        if (n % 3 == 0)
        {
            return isPowerOfThree(n / 3);
        }
        else
        {
            return false;
        }
    }
    
    // O(log3 n)
    bool isPowerOfThree(int n)
    {
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
    
    
    // O(1)
    public class Solution {
        public boolean isPowerOfThree(int n) {
        // 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 &&  1162261467%n==0);
    }
};