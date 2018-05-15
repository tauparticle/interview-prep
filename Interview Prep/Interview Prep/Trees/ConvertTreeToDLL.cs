using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    public static class ConvertTreeToDLL
    {
        public static void Test()
        {
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            root = treeToDoublyList(root);
        }

        // This is a modified in-order traversal adapted to this problem.
        // prev (init to NULL) is used to keep track of previously traversed node.
        // head pointer is updated with the list's head as recursion ends.
        public static void treeToDoublyList(TreeNode p, ref TreeNode prev, ref TreeNode head)
        {
            if (p == null) return;
            // traverse left
            treeToDoublyList(p.left, ref prev, ref head);
            // current node's left points to previous node
            p.left = prev;
            if (prev != null)
            {
                prev.right = p; // previous node's right points to current node
            }
            else
            {
                head = p; // current node (smallest element) is head of
            }
            // the list if previous node is not available
            // as soon as the recursion ends, the head's left pointer 
            // points to the last node, and the last node's right pointer
            // points to the head pointer.
            TreeNode right = p.right;
            head.left = p;
            p.right = head;
            // updates previous node
            prev = p;
            treeToDoublyList(right, ref prev, ref head);
        }

        // Given an ordered binary tree, returns a sorted circular
        // doubly-linked list. The conversion is done in-place.
        public static TreeNode treeToDoublyList(TreeNode root)
        {
            TreeNode prev = null;
            TreeNode head = null;
            treeToDoublyList(root, ref prev, ref head);
            return head;
        }
    }
}
