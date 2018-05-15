/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        int nodesPerLevel = 1;
        while (q.size() > 0)
        {
            for (int i=0; i<nodesPerLevel; ++i)
            {
                TreeNode* t = q.front();
                q.pop();
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                
                if (i == nodesPerLevel-1)
                {
                    result.push_back(t->val);
                }
            }
            nodesPerLevel = q.size();
        }
        
        return result;
    }
};