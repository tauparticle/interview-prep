
/*
 Given a sorted integer array without duplicates, return the summary of its ranges.
 
 For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 Hide Company Tags Google
 Hide Tags Array
 Hide Similar Problems (M) Missing Ranges (H) Data Stream as Disjoint Intervals

 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        
        int start = 0;
        int end = nums.size();
        
        while (start < end)
        {
            int i = start + 1;
            while (i < end && nums[i] == nums[i-1]+1) i++;
            
            if (i-start > 1)
            {
                ranges.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                start = i;
            }
            else
            {
                ranges.push_back(to_string(nums[i-1]));
                start++;
            }
        }
        
        return ranges;
    }
};