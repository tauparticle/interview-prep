/* Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Hide Company Tags Facebook
Hide Tags Tree

*/)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        
        if (!root) return 0;
        int sum = 0;
        
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, false));
        
        while(!s.empty())
        {
            auto lp = s.top();
            s.pop();
            
            if (lp.second && !lp.first->left && !lp.first->right)
            {
                sum += lp.first->val;
            }
            
            if (lp.first->left)
            {
                s.push(make_pair(lp.first->left, true));
            }
            if (lp.first->right)
            {
                s.push(make_pair(lp.first->right, false));
            }
        }
        
        return sum;
        
    }
};