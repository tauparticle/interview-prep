/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
       5
      / \
     4    8
    /   / \
   11  13  4
  /  \    / \
 7    2  5   1
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        
        vector<vector<int>> paths;
        
        if (root == NULL) {
            return paths;
        }
        vector<int> currentPaths;
        dfs(root, sum, paths, currentPaths);
        return paths;
    }
    
    void dfs (TreeNode * root, int sum, vector<vector<int>> & paths, vector<int> currentPath)
    {
        if (root == NULL) return;
        
        currentPath.push_back(root->val);
        if (root->val == sum && root->left == NULL && root->right == NULL)
        {
            paths.push_back(currentPath);
        }
        
        vector<int> leftCopy = vector<int>(currentPath.begin(), currentPath.end());
        vector<int> rightCopy = vector<int>(currentPath.begin(), currentPath.end());
        
        dfs(root->left, sum - root->val, paths, leftCopy);
        dfs(root->right, sum - root->val, paths, rightCopy);
    }
};