using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    public static class SubTrees
    {
        public static void Test()
        {
            // t2 is a subtree of t1
            int[] array1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
            int[] array2 = { 2, 4, 5, 8, 9, 10, 11 };

            TreeNode t1 = TreeNode.createTreeFromArray(array1);
            TreeNode t2 = TreeNode.createTreeFromArray(array2);

            if (IsSubTree(t1, t2))
                Console.WriteLine("t2 is a subtree of t1");
            else
                Console.WriteLine("t2 is not a subtree of t1");

            // t4 is not a subtree of t3
            int[] array3 = { 1, 2, 3 };
            TreeNode t3 = TreeNode.createTreeFromArray(array1);
            TreeNode t4 = TreeNode.createTreeFromArray(array3);

            if (IsSubTree(t3, t4))
                Console.WriteLine("t4 is a subtree of t3");
            else
                Console.WriteLine("t4 is not a subtree of t3");
        }




        // Space = O(log(n) + log(m))
        // runtime worst case = O(mn) or possibly O(n^2) if trees are identical
        // average case: O( n + km) where k is the number of occurrences of t2's root in T1
        public static bool IsSubTree(TreeNode t1, TreeNode t2)
        {
            if (t2 == null) return true;
            return SubTree(t1, t2);
        }

        public static bool SubTree(TreeNode t1, TreeNode t2)
        {
            if (t1 == null) // big tree empty while small tree has more nodes
                return false;

            if (t1.data == t2.data)
            {
                if (MatchTree(t1, t2)) return true;
            }

            return SubTree(t1.left, t2) || SubTree(t1.right, t2);

        }


        //Checks if the binary tree rooted at r1 contains the 
        // binary tree rooted at r2 as a subtree starting at r1.
        public static bool MatchTree(TreeNode r1, TreeNode r2)
        {
            if (r2 == null && r1 == null) return true; // nothing left in the subtree
            if (r1 == null || r2 == null) return false; //  big tree empty & subtree still not found
            if (r1.data != r2.data) return false; // data doesn’t match
            return (MatchTree(r1.left, r2.left) && MatchTree(r1.right, r2.right));
        }
    }
}
