/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the 
// depth of the two subtrees of every node never differ by more than 1.

public class Solution {
    
    // code runs in O(n) time and O(H) space where H is the height of the tree.  
    // this is the optimal solution
    public boolean isBalanced(TreeNode root) {
        
        return CheckHeight(root) != -1;
    }
    
    private int CheckHeight(TreeNode root) {
        
        if (root == null) {
            return 0;
        }
        
        // check if left path is balanced
        int leftDepth = CheckHeight(root.left);
        if (leftDepth == -1) {
            return -1;
        }
        
        // check if right path is balanced
        int rightDepth = CheckHeight(root.right);
        if (rightDepth == -1) {
            return -1;
        }
        
        // check if current node is balanced
        int delta = leftDepth - rightDepth;
        if (Math.abs(delta) > 1) {
            return -1; // not balanced
        }
        
        // return height
        return 1 + Math.max(leftDepth, rightDepth);
        
    }
}