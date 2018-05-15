/*
 
 22. Generate Parentheses   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 118780
 Total Submissions: 287907
 Difficulty: Medium
 Contributors: Admin
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 For example, given n = 3, a solution set is:
 
 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 Hide Company Tags Google Uber Zenefits
 Hide Tags Backtracking String
 Hide Similar Problems (M) Letter Combinations of a Phone Number (E) Valid Parentheses

 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> current(n*2, ' ');
        vector<string> results;
        doGenerateParens(n, n, current, 0, results);
        return results;
    }
    
    void doGenerateParens(int open, int closed, vector<char>& current, int index, vector<string>& results)
    {
        if (open == 0 && closed == 0)
        {
            results.push_back(string(current.data(), current.size()));
            return;
        }
        
        if (open > 0)
        {
            current[index] = '(';
            doGenerateParens(open-1, closed, current, index+1, results);
        }
        if (open < closed)
        {
            current[index] = ')';
            doGenerateParens(open, closed-1, current, index+1, results);
        }
    }
};
