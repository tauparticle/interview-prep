using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class PrintTreePaths
    {
        public static void Test()
        {
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            for (int i = 1; i < 25; ++i)
            {
                Console.WriteLine("Printing paths that sum up to " + i);
                PrintPaths(root, i);
            }
        }

        // Assuming balanced tree O(n log n) since there are n nodes and we're doing log(n) work each since the avg depth case of log(n).
        // If tree isn't balanced (one long left/right chain, it's O(n^2))
        public static void PrintPaths(TreeNode root, int sum)
        {
            if (root == null) return;

            // get the max depth of this tree
            int[] path = new int[getDepth(root)];
            findPath(root, path, sum, 0);
        }

        public static void findPath(TreeNode root, int[] path, int value, int level)
        {
            if (root == null) return;

            // put the current node into the path
            path[level] = root.data;

            int sum = 0;
            for (int i=level; i>=0; i--)
            {
                sum += path[i];
                if (sum == value)
                {
                    print(path, i, level);                    
                }
            }

            // branch left and right
            findPath(root.left, path, value, level+1);
            findPath(root.right, path, value, level+1);

            // remove the current node from path.
            path[level] = int.MinValue;
        }

        public static void print(int[] path, int start, int end)
        {
             Console.Write("Path:");
            for (int i=start; i<=end; ++i)
            {
                if (i > start)
                {
                    Console.Write("->");
                }

                Console.Write(path[i]);
            }

            Console.Write("\n");
        }

        public static int getDepth(TreeNode root)
        {
            if (root == null) return 0;

            return 1 + Math.Max(getDepth(root.left), getDepth(root.right));
        }
    }
}
