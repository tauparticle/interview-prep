/**

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

Show Company Tags
Hide Tags Depth-first Search
Hide Similar Problems (M) Nested List Weight Sum II



 /**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        
        int depthSum = 0;
        stack<Node> s;
        for (int i=nestedList.size()-1; i >= 0; i--)
        {
            s.push({ nestedList[i], 1});
        }
        
        while (!s.empty())
        {
            auto n = s.top();
            s.pop();
            
            if (n.ni.isInteger())
            {
                depthSum += n.ni.getInteger() * n.level;
            }
            else
            {
                auto list = n.ni.getList();
                for (int i=list.size()-1; i >= 0; i--)
                {
                    s.push({list[i], n.level+1});
                }
            }
        }
        return depthSum;
    }
    
private:
    
    struct Node
    {
        NestedInteger ni;
        int level;
    };
    
    
    
};
