package Graphs;

import CtCILibrary.TreeNode;

public class MirroredTrees {
	
	public static boolean AreTreesMirrored(TreeNode t1, TreeNode t2) {
		
		if (t1 == null && t2 == null) {
			return true;
		}
		
		if ((t1 != null && t2 == null) || (t2 != null && t1 == null)) {
			return false;
		}
		
		if (t1.data != t2.data) {
			return false;
		}
		return AreTreesMirrored(t1.left, t2.right) && AreTreesMirrored(t1.right, t2.left);
		
	}
	
	public static TreeNode MirrorTree(TreeNode root) {
		 
		if (root == null) {
			return null;
		}
		
		TreeNode tmp = new TreeNode(root.data);
		tmp.left = MirrorTree(root.right);
		tmp.right = MirrorTree(root.left);
		return tmp;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TreeNode t1 = new TreeNode(1);
		TreeNode t2 = new TreeNode(1);
		t1.left = new TreeNode(2);
		t2.right = new TreeNode(2);
		t1.left.right = new TreeNode(3);
		t2.right.left = new TreeNode(3);
		t1.left.left = new TreeNode(4);
		t2.right.right = new TreeNode(4);
		t2.right.right.left = new TreeNode(5);
		
		CtCILibrary.BTreePrinter.printNode(t1);
		CtCILibrary.BTreePrinter.printNode(t2);
		System.out.println("are trees mirrored = " + AreTreesMirrored(t1, t2));
		
		TreeNode t11 = new TreeNode(1);
		TreeNode t22 = new TreeNode(1);
		t11.left = new TreeNode(2);		
		t11.right = new TreeNode(3);
		t11.left.left = new TreeNode(4);
		t11.right.right = new TreeNode(5);
		
		t22.left = new TreeNode(2);
		t22.right = new TreeNode(3);
		t22.right.left = new TreeNode(4);
		t22.right.right = new TreeNode(5);
		
		CtCILibrary.BTreePrinter.printNode(t11);
		CtCILibrary.BTreePrinter.printNode(t22);
		System.out.println("are trees mirrored = " + AreTreesMirrored(t11, t22));
		
		CtCILibrary.BTreePrinter.printNode(t22);
		
		CtCILibrary.BTreePrinter.printNode(MirrorTree(t22));
		
		TreeNode mirrorT22 = MirrorTree(t22);
		System.out.println("Last 2 mirrors should be true = " + AreTreesMirrored(t22, mirrorT22));
		

	}

}
