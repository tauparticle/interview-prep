/*
40. Combination Sum II   QuestionEditorial Solution  My Submissions
Total Accepted: 89988
Total Submissions: 295121
Difficulty: Medium
Contributors: Admin
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Subscribe to see which companies asked this question

Hide Tags Array Backtracking
Hide Similar Problems (M) Combination Sum


*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> lists;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtracking(lists, current, candidates, target, 0);
        return lists;
    }
    
    void backtracking(vector<vector<int>>& lists, vector<int>& current, vector<int>& candidates, int remaining, int start)
    {
        if (remaining < 0) return;
        if (remaining == 0)
        {
            lists.push_back(current);
        }
        
        for (int i=start; i<candidates.size(); ++i)
        {
            // checking if neighboring values are duplicates.  Otherwise skip
            if (i > start && candidates[i] == candidates[i-1]) continue;
            current.push_back(candidates[i]);
            backtracking(lists, current, candidates, remaining - candidates[i], i+1);
            current.pop_back();
        }
    }
};