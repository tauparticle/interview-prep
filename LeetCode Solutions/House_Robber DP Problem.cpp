/*
 
 
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 
 Credits:
 Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 
 Hide Company Tags LinkedIn Airbnb
 Hide Tags Dynamic Programming
 Hide Similar Problems (M) Maximum Product Subarray (M) House Robber II (M) Paint House (E) Paint Fence (M) House Robber III

 */

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        // array to store the money
        vector<int> mark(nums.size(), 0);
        
        // infer from formula from problem:
        // mark[i] = max(num[i] + mark[i-2], mark[i-1]);
        // initialize the first two
        mark[0] = nums[0];
        mark[1] = max(nums[0], nums[1]);
        
        // using DP to mark the max money in the loop
        for (int i=2; i<nums.size(); ++i)
        {
            mark[i] = max(nums[i] + mark[i-2], mark[i-1]);
        }
        
        // last entry in mark has the cash prize
        return mark[nums.size()-1];
        
        // this can be optimized by tracking the past 2 values rather than O(n) elements
        
    }
    
};