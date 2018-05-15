package RandomNodeFromBST;

import CtCILibrary.AssortedMethods;
import CtCILibrary.TreeNode;

public class Question {
	
	public static TreeNode getKthNode(TreeNode root, int k) {
		int leftSize = root.left == null ? 0 : root.left.size();
		if (k < leftSize) {
			return getKthNode(root.left, k);
		} else if (k == leftSize) {
			return root;
		} else {
			return getKthNode(root.right, k - leftSize - 1);
		}
	}
	
	public static TreeNode getRandomNode(TreeNode root) {
		int k = (int) (Math.random() * root.size());
		return getKthNode(root, k);
	}
	
	
	public static void main(String [] args) throws Exception  {
		TreeNode root = AssortedMethods.randomBST(20, 0, 100);
		for (int i = 0; i < root.size(); i++) {
			TreeNode node = getKthNode(root, i);
			System.out.println(i + ": " + node.data);
		}
	}
}
