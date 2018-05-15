/*238. Product of Array Except Self   QuestionEditorial Solution  My Submissions
Total Accepted: 69152
Total Submissions: 150218
Difficulty: Medium
Contributors: Admin
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Hide Company Tags Amazon LinkedIn Apple Facebook Microsoft
Hide Tags Array
Hide Similar Problems (H) Trapping Rain Water (M) Maximum Product Subarray (H) Paint House II

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> output(size,1);
        /* calculate left product */
        int left_product = 1;
        for (int i=1;i<size;i++) {
            left_product *= nums[i-1];
            output[i] *= left_product;
            cout << "output[" << i << "]=" << output[i] << ", leftProduct = " << left_product << endl;
        }
        /* calculate right product */
        int right_product = 1;
        for (int i=size-2;i>=0;i--) {
            right_product *= nums[i+1];
            output[i] *= right_product;
            cout << "output[" << i << "]=" << output[i] << ", rightProduct = " << right_product << endl;
        }
        return output;
    }
};