/*
 Given a positive integer num, write a function which returns True if num is a perfect square else False.
 
 Note: Do not use any built-in library function such as sqrt.
 
 Example 1:
 
 Input: 16
 Returns: True
 Example 2:
 
 Input: 14
 Returns: False
 Credits:
 Special thanks to @elmirap for adding this problem and creating all test cases.
 
 Hide Company Tags LinkedIn
 Hide Tags Binary Search Math
 Hide Similar Problems (M) Sqrt(x)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long low = 0;
        long high = num;
        
        if (num < 2) return true;
        
        while (low < high)
        {
            long mid = (low + high ) / 2;
            long mid2 = mid*mid;
            if (mid2 == num)
            {
                return true;
            }
            else if (mid2 < num)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return false;
    }
};