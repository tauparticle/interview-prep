/* 301. Remove Invalid Parentheses   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 27122
 Total Submissions: 78947
 Difficulty: Hard
 Contributors: Admin
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 
 Note: The input string may contain letters other than the parentheses ( and ).
 
 Examples:
 "()())()" -> ["()()()", "(())()"]
 "(a)())()" -> ["(a)()()", "(a())()"]
 ")(" -> [""]
 Credits:
 Special thanks to @hpplayer for adding this problem and creating all test cases.
 
 Hide Company Tags Facebook
 Hide Tags Depth-first Search Breadth-first Search
 Hide Similar Problems (E) Valid Parentheses
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        int rmLeft = 0;
        int rmRight = 0;
        // loop and count open/close braces.
        // negate left with every right to find number of
        // remaining open right
        for (char c : s) {
            if (c == '(') {
                rmLeft++;
            } else if(c == ')') {
                if (rmLeft != 0) {
                    rmLeft--;
                } else {
                    rmRight++;
                }
            }
        }
        
        cout << "rmLeft: " << rmLeft << ", rmRight: " << rmRight << endl;
        
        set<string> res;
        string tmp;
        dfs(s, 0, tmp, res, rmLeft, rmRight, 0);
        return vector<string>(res.begin(), res.end());
        
    }
    
    // basically DFS backtrace possible substrings with fast abort and collect possible results
    void dfs(string& s, int i, string tmp, set<string>& res, int rmLeft, int rmRight, int openCount)
    {
        if (rmLeft < 0 || rmRight < 0 || openCount < 0) {
            return;
        }
        
        if (i == s.length()) {
            if (rmLeft == 0 && rmRight == 0 && openCount == 0) {
                res.insert(tmp);
            }
            return;
        }
        
        char c = s[i];
        int len = s.length();
        if (c == '(') {
            dfs(s, i + 1, tmp, res, rmLeft - 1, rmRight, openCount);		   // not use (
            dfs(s, i + 1, tmp + c, res, rmLeft, rmRight, openCount + 1);       // use (
            
        } else if (c == ')') {
            dfs(s, i + 1, tmp, res, rmLeft, rmRight - 1, openCount);	        // not use  )
            dfs(s, i + 1, tmp + c, res, rmLeft, rmRight, openCount - 1);  	    // use )
        } else {
            dfs(s, i + 1, tmp + c, res, rmLeft, rmRight, openCount);
        }
        tmp.resize(len);
    }
};
