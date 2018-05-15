/*Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int minDepth(TreeNode root) {
        return minDepthBfs(root);
    }
    
    // O(n) runtime, O(n) space.  This performs better for highly unbalanced trees because we termiate at the
    // first leaf node we find.  However for perfectly balanced trees, we have to traverse all nodes and has a worse case space
    // complexity of O(n) due to the extra space needed to store current level nodes in the queue.
    private int minDepthBfs(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        TreeNode rightMost = root;
        int depth = 1;
        while(!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left == null && node.right == null) break;  // first leaf node discovered.  Quitting time!
            if (node.left != null) q.add(node.left);
            if (node.right != null) q.add(node.right);
            if (node == rightMost) {
                depth++;
                rightMost = (node.right != null) ? node.right : node.left;
            }
        }
        
        return depth;
    }
    
    // O(n) runtime and O(log n) space.  Need to visit every node no matter what
    private int minDepthDfs(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null) return minDepth(root.right) + 1;
        if (root.right == null) return minDepth(root.left) + 1;
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}