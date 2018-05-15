/*

Notes Auto Saved.
|||

Type here...(Markdown is enabled)
​
163. Missing Ranges   QuestionEditorial Solution  My Submissions
Total Accepted: 18493
Total Submissions: 61739
Difficulty: Medium
Contributors: Admin
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Hide Company Tags Google
Hide Tags Array
Hide Similar Problems (M) Summary Ranges


*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string> ranges;
        
        int from = lower - 1;
        int to = upper + 1;
        
        for (int num : nums)
        {
            to = num;
            checkAddRange(ranges, from, to);
            from = num;
        }
        
        checkAddRange(ranges, from, upper+1);
       
       return ranges;
    }
    
    void checkAddRange(vector<string>& ranges, int from, int to)
    {
       if (from + 1 >= to) return;
       if (from + 2 == to) ranges.push_back(to_string(from+1));
       if (from + 2 < to) ranges.push_back(to_string(from+1) + "->" + to_string(to-1));
    }
};