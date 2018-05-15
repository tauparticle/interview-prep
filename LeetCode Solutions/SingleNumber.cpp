/*Given an array of integers, every element appears twice except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */


class Solution {
    public:
    
    // solution is to XOR all numbers together.  2 numbers XORd will cancel themselves out,
    // leaving the one number without a matching pair.
    int singleNumber(int A[], int n) {
        int val = 0;
        for (int i=0; i<n; ++i) {
            val = val ^ A[i];
        }
        return val;
    }
};