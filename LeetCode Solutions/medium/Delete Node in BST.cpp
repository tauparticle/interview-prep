/*
 450. Delete Node in a BST   QuestionEditorial Solution  My Submissions
 Total Accepted: 1634
 Total Submissions: 5545
 Difficulty: Medium
 Contributors: tsipporah5945
 Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 
 Basically, the deletion can be divided into two stages:
 
 Search for a node to remove.
 If the node is found, delete the node.
 Note: Time complexity should be O(height of tree).
 
 Example:
 
 root = [5,3,6,2,4,null,7]
 key = 3
 
     5
    / \
   3   6
  / \   \
 2   4   7
 
 Given key to delete is 3. So we find the node with value 3 and delete it.
 
 One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 
     5
    / \
   4   6
  /     \
 2       7
 
 Another valid answer is [5,2,6,null,4,null,7].
 
    5
   / \
  2   6
   \   \
    4   7
 Hide Company Tags Uber
 Hide Tags Tree

 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        
        if (root == null) {
            return null;
        }
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            // found the node.
            
            // no children exist
            if (root.left == null && root.right == null) {
                root = null;
            }
            else if (root.left == null || root.right == null) {
                root = root.left == null ? root.right : root.left;
            }
            else {
                
                // both children exist
                // replace current value with min from right node and remove the min node
                TreeNode min = findMinNode(root.right);
                root.val = min.val;
                root.right = deleteNode(root.right, min.val);
            }
        }
        
        return root;
    }
    
    private TreeNode findMinNode(TreeNode root) {
        TreeNode previous = null;
        while (root != null) {
            previous = root;
            root = root.left;
        }
        
        return previous;
    }
}
