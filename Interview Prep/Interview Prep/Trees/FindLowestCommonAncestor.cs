using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    public static class FindLowestCommonAncestor
    {
        public static void Test()
        {
            Console.WriteLine("\nFind Lowest Common Ancestor");
            var a = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            Console.WriteLine("Lowest Common Ancestor between " + root.left.left.data + " + and " +
                              root.right.right.data);
            var lca = GetCommonAncestor(root, root.left.left, root.right.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.left.left.data + " + and " + root.left.right.data);
            lca = GetCommonAncestor(root, root.left.left, root.left.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.data + " + and " + root.left.right.data);
            lca = GetCommonAncestor(root, root, root.left.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.data + " + and " + root.left.data);
            lca = GetCommonAncestor(root, root, root.left);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.left.data + " + and " + root.left.data);
            lca = GetCommonAncestor(root, root.left, root.left);
            Console.WriteLine(lca == null ? "null" : lca.data.ToString());

            Console.WriteLine("Lowest Common Ancestor between " + root.left.data + " + and " + root.left.left.data);
            lca = GetCommonAncestor(root, root.left, root.left.left);
            Console.WriteLine(lca.data);

            /// test using bottom up approach
            Console.WriteLine("Bottom up approach");
            Console.WriteLine("Lowest Common Ancestor between " + root.left.left.data + " + and " +
                              root.right.right.data);
            lca = LCA(root, root.left.left, root.right.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.left.left.data + " + and " + root.left.right.data);
            lca = LCA(root, root.left.left, root.left.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.data + " + and " + root.left.right.data);
            lca = LCA(root, root, root.left.right);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.data + " + and " + root.left.data);
            lca = LCA(root, root, root.left);
            Console.WriteLine(lca.data);

            Console.WriteLine("Lowest Common Ancestor between " + root.left.data + " + and " + root.left.data);
            lca = LCA(root, root.left, root.left);
            Console.WriteLine(lca == null ? "null" : lca.data.ToString());

            Console.WriteLine("Lowest Common Ancestor between " + root.left.data + " + and " + root.left.left.data);
            lca = LCA(root, root.left, root.left.left);
            Console.WriteLine(lca.data);

        }

        // runs in O(n) time for balanced tree, because IsDecendent is called on 2n nodes in the first call, after that branching covers 2n/2 nodes and then 2n/4
        // then 2n/8.  If you plot this on a graph, it's linear O(n) 
        // which results in O(n).  Worst case is O(n^2) for unbalanced degenerate tree
        public static TreeNode GetCommonAncestor(TreeNode root, TreeNode a, TreeNode b)
        {
            if (root == null) return null;
            if (a == null || b == null) return root;

            bool a_on_left = IsDecendent(root.left, a);
            bool b_on_left = IsDecendent(root.left, b);
            if (a_on_left != b_on_left)
            {
                // root is the common ancestor
                return root;
            }

            TreeNode nextRoot = a_on_left ? root.left : root.right;
            return GetCommonAncestor(nextRoot, a, b);
        }

        /// <summary>
        /// Determines if a node is a decendent of a root
        /// </summary>
        public static bool IsDecendent(TreeNode root, TreeNode findMe)
        {
            if (root == null) return false;
            if (root == findMe) return true;
            return IsDecendent(root.left, findMe) || IsDecendent(root.right, findMe);
        }

        // Bottom up approach 
        // Worse case O(n)
        // We traverse from the bottom, and once we reach a node which matches one of the two nodes, we pass it up to its parent. 
        // The parent would then test its left and right subtree if each contain one of the two nodes. If yes, then the parent must be
        // the LCA and we pass its parent up to the root. If not, we pass the lower node which contains either one of the two nodes 
        // (if the left or right subtree contains either p or q), or NULL (if both the left and right subtree does not contain either p or q) up.
        public static TreeNode LCA(TreeNode root, TreeNode p, TreeNode q)
        {
            if (root == null) return null;
            if (root == p || root == q) return root;
            TreeNode L = LCA(root.left, p, q);
            TreeNode R = LCA(root.right, p, q);
            if (L != null && R != null) return root; // if p and q are on both sides
            return L ?? R; // either one of p,q is on one side OR p,q is not in L&R subtrees
        }
    }
}
