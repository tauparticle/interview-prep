using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.DataStructures
{
    public static class TestSuffixTrees
    {
        public static void Test()
        {
            SuffixTree st = new SuffixTree("mississippi");
            string[] stringList = { "is", "sip", "hi", "sis" };
            foreach (var s in stringList)
            {
                var indexes = st.search(s);
                if (indexes != null)
                {
                    string ind = string.Empty;
                    foreach (var i in indexes) ind = string.Concat(ind, i, ",");
                    Console.WriteLine("{0} in {1} = {2}", s, "mississippi", ind);
                }
            }
        }
    }


    public class SuffixTreeNode
    {
        private Dictionary<char, SuffixTreeNode> children = new Dictionary<char, SuffixTreeNode>();
        private char value;
        private List<int> indexes = new List<int>();

        public void InsertString(string s, int index)
        {
            this.indexes.Add(index);
            if (!string.IsNullOrEmpty(s))
            {
                this.value = s[0];
                SuffixTreeNode child;
                if (!this.children.TryGetValue(this.value, out child))
                {
                    child = new SuffixTreeNode();
                    this.children.Add(this.value, child);
                }

                string remainder = s.Substring(1);
                child.InsertString(remainder, index);

            }
        }

        public List<int> Search(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return this.indexes;
            }

            char first = s[0];
            if (this.children.ContainsKey(first))
            {
                string remainder = s.Substring(1);
                return this.children[first].Search(remainder);
            }

            // not found
            return null;
        }
    }

    public class SuffixTree
    {
        private SuffixTreeNode root = new SuffixTreeNode();

        public SuffixTree(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                string suffix = s.Substring(i);
                root.InsertString(suffix, i);
            }
        }

        public List<int> search(String s)
        {
            return root.Search(s);
        }
    }
}
