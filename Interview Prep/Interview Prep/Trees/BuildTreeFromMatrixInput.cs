using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class BuildTreeFromMatrixInput
    {
        public static void Test()
        {
            int[,] input = new int[,] {{2, 4}, {1, 2}, {3, 6}, {1, 3}, {2, 5}};
            TreeNode root = BuildTreeFrom2DInput(input, 5);
        }

        public static TreeNode BuildTreeFrom2DInput(int[,] input, int rows)
        {
            /* a) The first number in each line is a parent. 
               b) Second number is a child. 
               c) The left child always shows up in the input before the right child. */

            Dictionary<int, HashSet<int>> parentToChildrenMap = new Dictionary<int, HashSet<int>>();
            Dictionary<int, int> childToParentMap = new Dictionary<int, int>();
            
            for (int i = 0; i < rows; ++i)
            {
                int parent = input[i,0];
                int child = input[i,1];

                HashSet<int> children;
                if (!parentToChildrenMap.TryGetValue(parent, out children))
                {
                    children = new HashSet<int>();
                    parentToChildrenMap.Add(parent, children);
                }

                children.Add(child);

                childToParentMap[child] = parent;
            }

            // walk through the child->parent map until we find a child with no parent.  That's our root
            int rootKey = -1;
            foreach (KeyValuePair<int, int> kvp in childToParentMap)
            {
                if (!childToParentMap.ContainsKey(kvp.Value))
                {
                    rootKey = kvp.Value;
                    break;
                }
            }

            // recursively rebuild the tree from the root key
            return BuildTree(parentToChildrenMap, rootKey);

        }

        private static TreeNode BuildTree(Dictionary<int, HashSet<int>> parentToChildrenMap, int key)
        {
            TreeNode root = new TreeNode(key);

            if (!parentToChildrenMap.ContainsKey(key))
            {
                // base case, we're a child
                return root;
            }

            // go through children set, assuming the order is always left child then right child
            HashSet<int> children = parentToChildrenMap[key];
            int count = 0;
            
            foreach (int childKey in children)
            {
                if (count == 0)
                {
                    root.left = BuildTree(parentToChildrenMap, childKey);
                }
                else
                {
                    root.right = BuildTree(parentToChildrenMap, childKey);
                }
                count++;
            }

            return root;
        }
    }
}
