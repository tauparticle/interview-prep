package TreeProblems;

import CtCILibrary.TreeNode;

public class IsNestedSubtree {
	
	public static boolean IsNestedTree(TreeNode root, TreeNode node)
	{
		if (root == null) {
			return node == null;
		}
		
		TreeNode commonRoot = FindNode(root, node);
		
		
		return AreTreesEqual(commonRoot, node);
		
	}
	
	private static boolean AreTreesEqual(TreeNode a, TreeNode b)
	{
		if (a == null ) return b == null;
		
		if ((a != null && b == null) || (a == null && b != null)) return false;
		
		if (a != b) return false;
		
		return AreTreesEqual(a.left, b.left) && AreTreesEqual(a.right, b.right);
	}
	
	private static TreeNode FindNode(TreeNode root, TreeNode node) 
	{
		if (root == null) return null;
		
		if (root == node) return root;
		
		TreeNode left = FindNode(root.left, node);
		if (left != null) {
			return left;
		}
		
		return FindNode(root.right, node);
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TreeNode root = TreeNode.createMinimalBST(new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16});
		
		TreeNode child = root.right.left;
		
		System.out.println("child is root = " + IsNestedTree(root, child));
		
		

	}

}
