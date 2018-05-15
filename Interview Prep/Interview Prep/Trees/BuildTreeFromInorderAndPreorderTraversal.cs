using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    public static class BuildTreeFromInorderAndPreorderTraversal
    {

        public static void Test()
        {
            int[] preorder = {7, 10, 4, 3, 1, 2, 8, 11};
            int[] inorder = {4, 10, 3, 1, 7, 11, 8, 2};
            var mapIndex = mapToIndices(inorder);
            TreeNode root = buildInorderPreorder(inorder, 0, preorder, 0, inorder.Length - 1, 0, mapIndex);
        }

        // a fast lookup for inorder's element -> index
        public static Dictionary<int, int> mapToIndices(int[] inorder)
        {
            Dictionary<int, int> mapIndex = new Dictionary<int, int>();
            for (int i = 0; i < inorder.Length; i++)
            {
                mapIndex[inorder[i]] = i;
            }
            return mapIndex;
        }

        // precondition: mapToIndices must be called before entry
        public static TreeNode buildInorderPreorder(int[] inorder, int inorderIndex, int[] preorder, int preorderIndex, int n, int offset, Dictionary<int, int> mapIndex )
        {
            if (n == 0) return null;
            int rootVal = preorder[preorderIndex];
            int i = mapIndex[rootVal] - offset; // the divider's index
            TreeNode root = new TreeNode(rootVal);
            root.left = buildInorderPreorder(inorder, inorderIndex, preorder, preorderIndex + 1, i, offset, mapIndex);
            root.right = buildInorderPreorder(inorder, inorderIndex + i + 1, preorder, preorderIndex + i + 1, n - i - 1, offset + i + 1, mapIndex);
            return root;
        }
    }
}
