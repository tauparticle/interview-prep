/*230. Kth Smallest Element in a BST   QuestionEditorial Solution  My Submissions
Total Accepted: 69621
Total Submissions: 170299
Difficulty: Medium
Contributors: Admin
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Bloomberg Uber Google
Hide Tags Binary Search Tree
Hide Similar Problems (M) Binary Tree Inorder Traversal
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        s.push(root);
        
        while (true)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            if (s.empty())
            {
                break;
            }
            cur = s.top();
            s.pop();
            
            k--;
            if (k == 0)
            {
                return cur->val;
            }
            
            cur = cur->right;
            
        }
        
        return INT_MIN;
        
    }
};