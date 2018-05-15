/*
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 
 Calling next() will return the next smallest number in the BST.
 
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 
 Hide Company Tags LinkedIn Google Facebook Microsoft
 Hide Tags Tree Stack Design
 Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Flatten 2D Vector (M) Zigzag Iterator (M) Peeking Iterator (M) Inorder Successor in BST

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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        
        goLeftYoungMan(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return m_stack.size() > 0;
    }
    
    /** @return the next smallest number */
    int next() {
        auto curr = m_stack.top();
        m_stack.pop();
        goLeftYoungMan(curr->right);
        return curr->val;
    }
    
private:
    
    void goLeftYoungMan(TreeNode* node)
    {
        while (node)
        {
            m_stack.push(node);
            node = node->left;
        }
    }
    
    stack<TreeNode*> m_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */