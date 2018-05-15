using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class NextInorderSuccessor
    {

        public static TreeNode reverseInorderSucc(TreeNode n)
        {
            if (n == null) return null;

            // Found left children -> return left most node of right subtree
            if (n.parent == null || n.left != null)
            {
                return rightMostChild(n.left);
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

        public static TreeNode inorderSucc(TreeNode n)
        {
            if (n == null) return null;

            // Found right children -> return left most node of right subtree
            if (n.parent == null || n.right != null)
            {
                return leftMostChild(n.right);
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

        public static TreeNode leftMostChild(TreeNode n)
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

        public static TreeNode rightMostChild(TreeNode n)
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

        public static void Test()
        {
            var a = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);


            for (int i = 0; i < a.Length; i++)
            {
                TreeNode node = root.find(a[i]);
                TreeNode next = inorderSucc(node);
                if (next != null)
                {
                    Console.WriteLine(node.data + "->" + next.data);
                }
                else
                {
                    Console.WriteLine(node.data + "->" + "null");
                }
            }

            TestReverse();
        }

        public static void TestReverse()
        {
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);


            for (int i = a.Length-1; i >= 0; i--)
            {
                TreeNode node = root.find(a[i]);
                TreeNode next = reverseInorderSucc(node);
                if (next != null)
                {
                    Console.WriteLine(node.data + "->" + next.data);
                }
                else
                {
                    Console.WriteLine(node.data + "->" + "null");
                }
            }
        }



       
    }
}