using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class IsTreeBalanced
    {
        public static void Test()
        {

            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            Console.WriteLine("Tree is balanced: " + IsTreeBalance(root));
            root.right.right.right.setRightChild(new TreeNode(11));
            Console.WriteLine("Tree is balanced: " + IsTreeBalance(root));

            Console.WriteLine("Common ancestor of 1 & 4 = " +
                              FindCommonAncestor(root, root.left.left, root.left.right.right).data);
        }

        // Top down assuming no links to parents.
        public static TreeNode FindCommonAncestor(TreeNode root, TreeNode a, TreeNode b)
        {
            if (root == null) throw new ArgumentNullException("root");
            if (a == null) throw new ArgumentNullException("a");
            if (b == null) throw new ArgumentNullException("b");

            bool a_is_on_left = IsDecendent(root.left, a);
            bool b_is_on_right = IsDecendent(root.right, b);

            if (a_is_on_left && b_is_on_right) return root;
            if (a_is_on_left && !b_is_on_right) return FindCommonAncestor(root.left, a, b);
            if (!a_is_on_left && b_is_on_right) return FindCommonAncestor(root.right, a, b);
            return null; // no ancestor
        }
        
        public static bool IsDecendent(TreeNode node, TreeNode findMe)
        {
            if (node != null)
            {
                if (node == findMe)
                {
                    return true;
                }

                return IsDecendent(node.left, findMe) || IsDecendent(node.right, findMe);
            }
            return false;
        }

        public static bool IsTreeBalance(TreeNode root)
        {
            return GetHeight(root) != -1;
        }

        public static int GetHeight(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }

            int leftHeight = GetHeight(node.left);
            if (leftHeight == -1) return -1;

            int rightHeight = GetHeight(node.right);
            if (rightHeight == -1) return -1;

            int diff = Math.Abs(leftHeight - rightHeight);
            if (diff > 1)
            {
                return -1;
            }

            return Math.Max(GetHeight(node.left), GetHeight(node.right)) + 1;
        }
    }
}

