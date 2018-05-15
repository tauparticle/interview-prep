
/*
 You need to consider the following 4 cases to delete a BST node :
 
 1. First case: left and right child nodes are null.
 
 Simply remove the node from the tree.
 
 2. Second and Third cases: Either the Left child node or the right child node is null .
 
 Remove the node and replace it with its child.
 
 3. Fourth case: Left and right child nodes are not null.
 
 Find the node with the minimum value in the right subtree of the node to be deleted. Put this minimum value in the node to be deleted. Delete the node which had the minimum value.
 */


// runtime O(log n)
// space O(log n)
public TreeNode delete(TreeNode root, int data) {
        if(root == null) { 
            return null;
        } else if(data < root.data) {
            root.left = delete(root.left, data);
        } else if(data > root.data) {
            root.right = delete(root.right, data);
        } else { //element found
            if(root.left != null && root.right != null) { //full node case
                root.data = findMin(root.right).data;    
                root.right = delete(root.right, root.data);
            } else if(root.left == null && root.right == null) {
                root = null;
            }  
            else if(root.left == null) {
                root = root.right;
            } else if(root.right == null) {
                root = root.left;                
            }                
        }
        return root;
    }