/*
39. Combination Sum   QuestionEditorial Solution  My Submissions
Total Accepted: 119850
Total Submissions: 348483
Difficulty: Medium
Contributors: Admin
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
Hide Company Tags Snapchat Uber
Hide Tags Array Backtracking
Hide Similar Problems (M) Letter Combinations of a Phone Number (M) Combination Sum II (M) Combinations (M) Combination Sum III (M) Factor Combinations (M) Combination Sum IV

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> lists;
        vector<int> tmp;
        backtrack(lists, tmp, candidates, target, 0);
        return lists;
    }
    
    void backtrack(vector<vector<int>>& lists, vector<int>& tmp, vector<int>& candidates, int remaining, int start)
    {
        if (remaining < 0)
        {
            return;
        }
        
        if (remaining == 0)
        {
            vector<int> clone(tmp.begin(), tmp.end());
            lists.push_back(clone);
        }
        
        for (int i=start; i<candidates.size(); ++i)
        {
            tmp.push_back(candidates[i]);
            backtrack(lists, tmp, candidates, remaining - candidates[i], i);
            tmp.pop_back();
        }
    }
};