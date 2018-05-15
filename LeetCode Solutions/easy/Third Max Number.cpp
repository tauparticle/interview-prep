/*
414. Third Maximum Number   QuestionEditorial Solution  My Submissions
Total Accepted: 1155
Total Submissions: 3979
Difficulty: Easy
Contributors: ZengRed , 1337c0d3r
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
Hide Company Tags Amazon
Hide Tags Array
Hide Similar Problems (M) Kth Largest Element in an Array


*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        int count = 0;
        for (int n : nums)
        {
            if (n > first)
            {
                third = second;
                second = first;
                first = n;
                count++;
            }
            else if (n > second && n < first)
            {
                third = second;
                second = n;
                count++;
            }
            else if (n > third && n < second)
            {
                third = n;
                count++;
            }
        }
        
        return count >= 3 ? third : first;
        
    }
};