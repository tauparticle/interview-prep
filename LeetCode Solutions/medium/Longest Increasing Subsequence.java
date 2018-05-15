/*
 300. Longest Increasing Subsequence   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 55748
 Total Submissions: 150688
 Difficulty: Medium
 Contributors: Admin
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 
 Your algorithm should run in O(n2) complexity.
 
 Follow up: Could you improve it to O(n log n) time complexity?
 
 Credits:
 Special thanks to @pbrother for adding this problem and creating all test cases.
 
 Hide Company Tags Microsoft
 Hide Tags Dynamic Programming Binary Search
 Hide Similar Problems (M) Increasing Triplet Subsequence (H) Russian Doll Envelopes
*/


public class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0)
        {
            return 0;
        }
        
        int[] longestSequenceLength = new int[nums.length];
        for (int i=0; i<nums.length; ++i)
        {
            longestSequenceLength[i] = 1;
        }
        
        int maxLength = 1;
        for (int i=1; i<nums.length; ++i)
        {
            int length = 1;
            for (int j = 0; j<i; ++j)
            {
                if (nums[j] < nums[i] && longestSequenceLength[j] + 1 > length)
                {
                    length = longestSequenceLength[j] + 1;
                }
            }
            longestSequenceLength[i] = length;
            maxLength = Math.max(maxLength,  length);
        }
        
        return maxLength;
    }
}
