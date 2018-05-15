/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Hide Company Tags Google Facebook
Hide Tags Array Union Find
Hide Similar Problems (M) Binary Tree Longest Consecutive Sequence

*/

class Solution {
public:

    // solution is O(n) runtime, because we only visit each element once.  
    // O(n) space.
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        
        while (!numSet.empty())
        {
            auto iter = numSet.begin();
            int n = *iter;
            int count = 1;
            // expand +/i around n in both directions and increment run count
            // remove elements from the set, since we never have to revisit them again
            for (int i=n+1; ; ++i)
            {
                auto it = numSet.find(i);
                if (it != numSet.end())
                {
                    numSet.erase(it);
                    count++;
                }
                else
                {
                    break;
                }
            }
            
            for (int i=n-1; ; --i)
            {
                auto it = numSet.find(i);
                if (it != numSet.end())
                {
                    numSet.erase(it);
                    count++;
                }
                else
                {
                    break;
                }
            }
            
            numSet.erase(iter);
            maxLength = max(maxLength, count);
        }
        
        return maxLength;
    }
};