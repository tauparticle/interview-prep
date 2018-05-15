/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Hide Company Tags Hulu
Hide Tags Bit Manipulation
Hide Similar Problems (M) Add Two Numbers

*/

class Solution {
public:
    int getSum(int a, int b) {
        
        if (a == 0) return b;
        if (b == 0) return a;

    	while (b != 0)
    	{
    	    // and gives us carry bits
		    int carry = a & b;
		    // xor gives us add w/out carry
		    a = a ^ b;
		    // shift up carry bits and repeat
		    b = carry << 1;
	    }
	
	    return a;
        
        
        
    }
};