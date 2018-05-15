/*
91. Decode Ways   QuestionEditorial Solution  My Submissions
Total Accepted: 88693
Total Submissions: 481713
Difficulty: Medium
Contributors: Admin
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Hide Company Tags Microsoft Uber Facebook
Hide Tags Dynamic Programming String

*/

// O(n) runtime & O(1) space.  
// This solution is similar to solving factorials with DP.  You keep track of the previous sub-work by tracking previous 2 calculations
class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        // if the string starts with a zero, it's categorically false
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1) return 1;
        
        // cache previous 2 values
        int pre2 = 1, pre1 = 1;
        int cur;
        
        for (int i = 1; i < n; ++i) 
        {
            cur = 0;
            int first = (s[i] - '0');  // current value
            int second = stoi(s.substr(i - 1, 2));  // previous 2 digit number
            if (1 <= first && first <= 9)  
            {
                // first number is valid digit, combine with previous first value sum
                cur += pre1;
            }
            if (10 <= second && second <= 26)
            {
                // second number is valid digit, combine with previous 2 digit sum
                cur += pre2;
            }
            
            // refresh cached values with current and previous 1
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};