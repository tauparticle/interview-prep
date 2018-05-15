/**
 Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 
 If two nodes are in the same row and column, the order should be from left to right.
 
     3
    / \
   9  20
  /  \
 15   7
 return its vertical order traversal as:
 [
 [9],
 [3,15],
 [20],
 [7]
 ]
 
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// runtime O(n)
// space O(n)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == nullptr)
        {
            return result;
        }
        
        map<int, vector<int>> lists;
        
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while (q.size() > 0)
        {
            auto n = q.front();
            q.pop();
            
            auto node = n.second;
            auto column = n.first;
            lists[column].push_back(node->val);
            
            if (node->left)
            {
                q.push(make_pair(column-1, node->left));
            }
            
            if (node->right)
            {
                q.push(make_pair(column+1, node->right));
            }
        }
        
        for (auto& kvp : lists)
        {
            result.push_back(kvp.second);
        }
        
        return result;
    }
    
};