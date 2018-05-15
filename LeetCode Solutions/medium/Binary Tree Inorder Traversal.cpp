
/*
94. Binary Tree Inorder Traversal   QuestionEditorial Solution  My Submissions
Total Accepted: 155265
Total Submissions: 365068
Difficulty: Medium
Contributors: Admin
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Company Tags Microsoft
Hide Tags Tree Hash Table Stack
Hide Similar Problems (M) Validate Binary Search Tree (M) Binary Tree Preorder Traversal (H) Binary Tree Postorder Traversal (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST (H) Closest Binary Search Tree Value II (M) Inorder Successor in BST

*/

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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> values;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (true)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            if (s.empty()) break;
            cur = s.top();
            s.pop();
            values.push_back(cur->val);
            cur = cur->right;
        }
        return values;
        
    }
};