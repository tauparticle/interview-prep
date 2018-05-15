namespace Interview_Prep
{
    using System.Collections.Generic;

    public class TreeNode
    {
        public int data;
        public TreeNode left, right, parent;
        public TreeNode(int d)
        {
            this.data = d;
            this.parent = null;
            this.left = null;
            this.right = null;
        }

        public void setLeftChild(TreeNode left)
        {
            this.left = left;
            if (left != null)
            {
                left.parent = this;
            }
        }

        public void setRightChild(TreeNode right)
        {
            this.right = right;
            if (right != null)
            {
                right.parent = this;
            }
        }

        public TreeNode find(int d)
        {
            if (d == this.data)
            {
                return this;
            }
            else if (d <= this.data)
            {
                return this.left != null ? this.left.find(d) : null;
            }
            else if (d > this.data)
            {
                return this.right != null ? this.right.find(d) : null;
            }
            return null;
        }


        public static TreeNode GenerateBST(int[] a, int left, int right)
        {
            if (left > right) return null;

            int mid = (left + right) / 2;
            TreeNode n = new TreeNode(a[mid]);
            n.setLeftChild(GenerateBST(a, left, mid - 1));
            n.setRightChild(GenerateBST(a, mid + 1, right));
            return n;
        }

        public static TreeNode createTreeFromArray(int[] array)
        {
            if (array.Length > 0)
            {
                TreeNode root = new TreeNode(array[0]);
                Queue<TreeNode> queue = new Queue<TreeNode>();
                queue.Enqueue(root);
                bool done = false;
                int i = 1;
                while (!done)
                {
                    TreeNode r = (TreeNode)queue.Peek();
                    if (r.left == null)
                    {
                        r.left = new TreeNode(array[i]);
                        i++;
                        queue.Enqueue(r.left);
                    }
                    else if (r.right == null)
                    {
                        r.right = new TreeNode(array[i]);
                        i++;
                        queue.Enqueue(r.right);
                    }
                    else
                    {
                        queue.Dequeue();
                    }
                    if (i == array.Length) done = true;
                }
                return root;
            }
            else
            {
                return null;
            }
        }
    }
}