using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public static class TestRankNode
    {
        public static void Test()
        {
            RankNode n = new RankNode(5);
            for (int i = 0; i < 50; ++i)
            {
                n.Insert(i);
            }

            for (int i = 0; i < 50; ++i)
            {
                Console.WriteLine("Rank of " + i + " is " + n.GetRank(i));
            }
        }
    }

    public class RankNode
    {
        public int leftSize = 0;
        public RankNode left, right;
        public int data;

        public RankNode(int d)
        {
            this.data = d;
            this.left = null;
            this.right = null;
        }

        /// <summary>
        /// Inserts node into tree O(log n)
        /// </summary>
        /// <param name="d"></param>
        public void Insert(int d)
        {
            if (d <= this.data)
            {
                if (this.left != null)
                {
                    this.left.Insert(d);
                }
                else
                {
                    this.left = new RankNode(d);
                }
                this.leftSize++;
            }
            else
            {
                if (right != null)
                {
                    this.right.Insert(d);
                }
                else
                {
                    this.right = new RankNode(d);
                }
            }
        }

        public int GetRank(int d)
        {
            if (this.data == d)
            {
                return this.leftSize;
            }
            if (d < this.data)
            {
                if (this.left == null)
                {
                    return -1;
                }
                return this.left.GetRank(d);
            }
            int rightRank = (this.right == null) ? -1 : this.right.GetRank(d);
            if (rightRank == -1)
            {
                return -1;
            }
            return this.leftSize + 1 + rightRank;
        }
    }
}
