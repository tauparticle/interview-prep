using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    // this problem uses find next inorder traversal and find next reverse inorder traveral algorithms.
    public static class FindBSTNodesThatSumUpToValue
    {
        public static void Test()
        {
            Console.WriteLine();
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            for (int i = 3; i < 20; ++i)
            {
                PrintSumNodesInBST(root, i);
            }
        }

        public static void PrintSumNodesInBST(TreeNode root, int sum)
        {
            TreeNode right = RightMostChild(root);
            TreeNode left = LeftMostChild(root);

            PrintSumNodesInBSTImpl(left, right, sum);
        }

        private static void PrintSumNodesInBSTImpl(TreeNode left, TreeNode right, int sum)
        {
            if (left.data > right.data)
            {
                // we're done.
                return;
            }

            if (left.data + right.data == sum)
            {
                Console.WriteLine("{0} + {1} = {2}", left.data, right.data, sum);
                // advance left and decrement right
                PrintSumNodesInBSTImpl(InorderSucc(left), ReverseInorderSucc(right), sum);
            }
            else if (left.data + right.data > sum)
            {
                // decrement right
                PrintSumNodesInBSTImpl(left, ReverseInorderSucc(right), sum);
            }
            else
            {
                PrintSumNodesInBSTImpl(InorderSucc(left), right, sum);
            }
        }

        public static TreeNode LeftMostChild(TreeNode n)
        {
            if (n == null)
            {
                return null;
            }
            while (n.left != null)
            {
                n = n.left;
            }
            return n;
        }

        public static TreeNode RightMostChild(TreeNode n)
        {
            if (n == null)
            {
                return null;
            }
            while (n.right != null)
            {
                n = n.right;
            }
            return n;
        }

        public static TreeNode ReverseInorderSucc(TreeNode n)
        {
            if (n == null) return null;

            // Found left children -> return left most node of right subtree
            if (n.parent == null || n.left != null)
            {
                return RightMostChild(n.left);
            }
            else
            {
                TreeNode q = n;
                TreeNode x = q.parent;
                // Go up until we’re on right instead of left
                while (x != null && x.right != q)
                {
                    q = x;
                    x = x.parent;
                }
                return x;
            }
        }

        public static TreeNode InorderSucc(TreeNode n)
        {
            if (n == null) return null;

            // Found right children -> return left most node of right subtree
            if (n.parent == null || n.right != null)
            {
                return LeftMostChild(n.right);
            }
            else
            {
                TreeNode q = n;
                TreeNode x = q.parent;
                // Go up until we’re on left instead of right
                while (x != null && x.left != q)
                {
                    q = x;
                    x = x.parent;
                }
                return x;
            }
        }
    }
}
