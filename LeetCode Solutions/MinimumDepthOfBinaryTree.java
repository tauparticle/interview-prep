/**
 * Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
       if (root == null) {
           return 0;
       }
       
       Queue<TreeNode> q = new LinkedList<TreeNode>();
       TreeNode tmp, magic = new TreeNode(0);
       int depth = 1;
       q.add(root);
       q.add(magic);
       
       while(!q.isEmpty()) {
           tmp = q.poll();
           if (tmp.equals(magic)) {
               if (!q.isEmpty()) {
                depth++;
                q.add(magic);
                continue;
               }
           }
           
           if (tmp.left == null && tmp.right == null) {
               return depth;
           }
           
           if (tmp.left != null) {
               q.add(tmp.left);
           }
           
           if (tmp.right != null) {
               q.add(tmp.right);
           }
       }
       
       return depth;
    }
}