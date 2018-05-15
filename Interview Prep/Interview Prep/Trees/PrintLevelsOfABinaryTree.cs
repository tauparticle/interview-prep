using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Trees
{
    using System.Collections.ObjectModel;

    public static class PrintLevelsOfABinaryTree
    {
        public static void Test()
        {
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            TreeNode t = root;
            TreeNode r = root;
            var levelList = ProduceTreeLevel(root);
            Console.WriteLine("Print tree levels in order");
           
            foreach (List<int> level in levelList)
            {
                foreach (int v in level)
                {
                    Console.Write(v + "->");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public static void InOrder(TreeNode root)
        {
            if (root == null) return;
            InOrder(root.left);
            Console.WriteLine(root.data);
            InOrder(root.right);
        }

        public static void ReverseInOrder(TreeNode root)
        {
            if (root == null) return;
            ReverseInOrder(root.right);
            Console.WriteLine(root.data);
            ReverseInOrder(root.left);
        }

        public static List<List<int>> ProduceTreeLevel(TreeNode root)
        {
            List<List<int>> levelList = new List<List<int>>();
            InOrderTraversal(root, levelList, 0);
            return levelList;
        }

        public static void InOrderTraversal(TreeNode node, List<List<int>> levelList, int level)
        {
            if (node == null) return;

            List<int> currentLevel = null;
            if (levelList.Count == level)
            {
                // need to create a new list
                currentLevel = new List<int>();
                levelList.Insert(level, currentLevel);
            }
            else
            {
                currentLevel = levelList[level];
            }

            InOrderTraversal(node.left, levelList, level+1);

            currentLevel.Add(node.data);

            InOrderTraversal(node.right, levelList, level + 1);
            
        }
    }
}
