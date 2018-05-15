/*270. Closest Binary Search Tree Value   QuestionEditorial Solution  My Submissions
 Total Accepted: 21642
 Total Submissions: 58557
 Difficulty: Easy
 Contributors: Admin
 Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 
 Note:
 Given target value is a floating point.
 You are guaranteed to have only one unique value in the BST that is closest to the target.
 Hide Company Tags Microsoft Google Snapchat
 Hide Tags Tree Binary Search
 Hide Similar Problems (M) Count Complete Tree Nodes (H) Closest Binary Search Tree Value II
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
    int closestValue(TreeNode* root, double target) {
        long long closest = LONG_MAX;
        traverse(root, target, closest);
        return closest;
    }
    
    void traverse(TreeNode* root, double target, long long& closest)
    {
        if (!root) return;
        if (abs(target - root->val) < abs(target - closest)) closest = root->val;
        if (target < root->val)
        {
            traverse(root->left, target, closest);
        }
        else
        {
            traverse(root->right, target, closest);
        }
    }
};
