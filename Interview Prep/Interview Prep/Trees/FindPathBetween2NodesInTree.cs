using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    using Interview_Prep.Trees;

    public static class FindPathBetween2NodesInTree
    {
        private static long s_numberOfChecksWithParentLinks;
        private static long s_numberOfChecksWithoutParentLinks;
        public static void Test()
        {
            s_numberOfChecksWithParentLinks = 0;
            s_numberOfChecksWithoutParentLinks = 0;
            TestWithParentLinks();
            TestWithoutParentLinks();
        }

        public static void TestWithoutParentLinks()
        {
            Console.WriteLine("\nWithout Parent Links");
            var a = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            Console.WriteLine("\npath between " + root.left.left.data + " + and " + root.right.right.data);
            var path = FindPathBetweenTwoNodes(root, root.left.left, root.right.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.left.left.data + " + and " + root.left.right.data);
            path = FindPathBetweenTwoNodes(root, root.left.left, root.left.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.data + " + and " + root.left.right.data);
            path = FindPathBetweenTwoNodes(root, root, root.left.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.data + " + and " + root.left.data);
            path = FindPathBetweenTwoNodes(root, root, root.left);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.left.data + " + and " + root.left.data);
            path = FindPathBetweenTwoNodes(root, root.left, root.left);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }
        }

        public static void TestWithParentLinks()
        {
            Console.WriteLine("\nWith Parent Links");
            var a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            TreeNode root = TreeNode.GenerateBST(a, 0, a.Length - 1);

            Console.WriteLine("\npath between " + root.left.left.data + " + and " + root.right.right.data);
            var path = FindPathBetweenTwoNodesWithParentLinks(root, root.left.left, root.right.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.left.left.data + " + and " + root.left.right.data);
            path = FindPathBetweenTwoNodesWithParentLinks(root, root.left.left, root.left.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.data + " + and " + root.left.right.data);
            path = FindPathBetweenTwoNodesWithParentLinks(root, root, root.left.right);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.data + " + and " + root.left.data);
            path = FindPathBetweenTwoNodesWithParentLinks(root, root, root.left);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }

            Console.WriteLine("\npath between " + root.left.data + " + and " + root.left.data);
            path = FindPathBetweenTwoNodesWithParentLinks(root, root.left, root.left);
            foreach (var node in path)
            {
                Console.Write(node.data + "->");
            }
        }



        ///------------ Solution assuming no links to parent node ------------------------------------

        public static List<TreeNode> FindPathBetweenTwoNodes(TreeNode root, TreeNode start, TreeNode end)
        {
            if (root == null || start == null || end == null) return null;
            List<TreeNode> path = new List<TreeNode>();
            if (start == end)
            {
                path.Add(start);
                return path;
            }

            // O(n) to get LCA
            TreeNode commonAncestor = FindLowestCommonAncestor.GetCommonAncestor(root, start, end);
            if (commonAncestor == null) return path; // start and end not not both under root

            // build a child/parent map of the nodes below the common ancestor to make path building easier
            Dictionary<TreeNode, TreeNode> childParentMap = new Dictionary<TreeNode, TreeNode>();
            BuildChildParentMap(commonAncestor, null, childParentMap);

            while (start != commonAncestor)
            {
                path.Add(start);
                start = childParentMap[start];
            }

            path.Add(commonAncestor);

            Stack<TreeNode> endPath = new Stack<TreeNode>();
            while (end != commonAncestor)
            {
                endPath.Push(end);
                end = childParentMap[end];
            }

            while (endPath.Count != 0)
            {
                path.Add(endPath.Pop());
            }
           

            return path;
        }

        public static void BuildChildParentMap(TreeNode root, TreeNode parent, Dictionary<TreeNode, TreeNode> childParentMap)
        {
            if (root == null)
            {
                return;
            }

            childParentMap.Add(root, parent);
            BuildChildParentMap(root.left, root, childParentMap);
            BuildChildParentMap(root.right, root, childParentMap);
        }


        

        
//----------------------- solution if tree nodes have links to parents -------------------------------------------


        public static List<TreeNode> FindPathBetweenTwoNodesWithParentLinks(TreeNode root, TreeNode start, TreeNode end)
        {
            if (root == null || start == null || end == null) return null;
            List<TreeNode> path = new List<TreeNode>();
            if (start == end)
            {
                path.Add(start);
                return path;
            }

            List<TreeNode> startPath = new List<TreeNode>();
            List<TreeNode> endPath = new List<TreeNode>();


            int startLevel = findLevel(root, start, 0);
            int endLevel = findLevel(root, end, 0);

            // can use a hashset of TreeNode to iterate until insertion fails.  that's the common ancestor
            if (startLevel > endLevel)
            {
                while (startLevel != endLevel)
                {
                    startPath.Add(start);
                    startLevel--;
                    start = start.parent;  // move parent up until at same level as end
                }
            }
            else if (endLevel > startLevel)
            {
                while (endLevel != startLevel)
                {
                    endPath.Add(end);
                    endLevel--;
                    end = end.parent;  // move parent up until at same level as end
                }
            }

            while (start != end)  // move both nodes up until they equal the lowest common ancestor
            {
                if (start == null || end == null) return null; 
                startPath.Add(start);
                endPath.Add(end);
                start = start.parent;
                end = end.parent;
            }

            path.AddRange(startPath); path.Add(start);
            endPath.Reverse();  // reverse the path.  Could use a stack instead of a List.
            path.AddRange(endPath);
           
            return path;
        }

        

        public static int findLevel(TreeNode root, TreeNode x, int level)
        {
            if (root == null) return -1;

            if (root == x)
            {
                return level;
            }

            level += 1;
            return Math.Max(findLevel(root.left, x, level), findLevel(root.right, x, level));
        }

       
    }
}
