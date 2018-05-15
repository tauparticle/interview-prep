using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class ValidateIsBST
    {
        public static bool IsValid(TreeNode node)
        {
            return isValidHelper(node, int.MinValue, int.MaxValue);

        }

        private static bool isValidHelper(TreeNode root, int minValue, int maxValue)
        {
            if (root == null)
            {
                // base case, nothing left to search, return true
                return true;
            }

            if (root.data > minValue && root.data < maxValue)
            {
                // now we call the recurive part to check its left and right subtrees
                return isValidHelper(root.left, minValue, root.data) && isValidHelper(root.right, root.data, maxValue);
            }
            
            // As the current node finds inappropriate node, return false immediately
            return false;
        }

        public static void Test()
        {
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            Console.WriteLine("BST is valid = " + IsValid(root));
            
        }
    }
}
