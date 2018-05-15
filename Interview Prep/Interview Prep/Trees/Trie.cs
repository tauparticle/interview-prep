using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    public class TrieNode
    {
        public char Key { get; private set; }
        public Dictionary<char, TrieNode> Children = new Dictionary<char, TrieNode>();
        public bool IsTerminator { get; set; }

        public TrieNode(char key)
        {
            this.Key = key;
            this.IsTerminator = false;
        }

        public TrieNode GetChild(char c)
        {
            TrieNode child;
            if (!this.Children.TryGetValue(c, out child))
            {
                return null;
            }
            return child;
        }

        public bool Contains(char c)
        {
            return this.Children.ContainsKey(c);
        }

        public TrieNode Insert(char c)
        {
            TrieNode node;
            if (!this.Children.TryGetValue(c, out node))
            {
                node = new TrieNode(c);
                this.Children[c] = node;
            }
            return node;
        }
    }


    public class Trie
    {
        const char CRootValue = 'a';
        private TrieNode root = new TrieNode(CRootValue);

        public TrieNode Insert(string str)
        {
            TrieNode node = this.root;
            foreach (char c in str)
            {
                node = this.Insert(c, node);
            }
            node.IsTerminator = true;
            return this.root;
        }

        public TrieNode Insert(char c, TrieNode node)
        {
            if (node.Contains(c))
            {
                return node.GetChild(c);
            }
            else
            {
                return node.Insert(c);
            }
        }

        public bool Contains(string str)
        {
            TrieNode node = root;
            foreach (char c in str)
            {
                node = node.GetChild(c);
                if (node == null)
                {
                    return false;
                }
            }

            if (node == null || !node.IsTerminator)
            {
                return false;
            }
            return true;
        }

        public List<string> AutoComplete(string prefix)
        {
            List<string> results = new List<string>();
            TrieNode node = root;
            foreach (char c in prefix)
            {
                node = node.GetChild(c);
                if (node == null)
                {
                    return results;
                }
            }

            this.doAutoComplete(prefix, string.Empty, results, node);
            return results;
        }

        private void doAutoComplete(string prefix, string suffix, List<string> results, TrieNode node)
        {
            if (node.IsTerminator)
            {
                results.Add(string.Concat(prefix, suffix));
            }

            foreach (KeyValuePair<char, TrieNode> kvp in node.Children)
            {
                suffix += kvp.Key;
                this.doAutoComplete(prefix, suffix, results, kvp.Value);
            }
        }
    }

    public static class TrieTest
    {
        public static void Test()
        {
            Trie node = new Trie();
            node.Insert("apple"); node.Insert("applebees"); node.Insert("app"); node.Insert("texas"); node.Insert("texas holdem");
            Console.WriteLine("Trie contains apple = " + node.Contains("apple"));
            List<string> list = node.AutoComplete("app");
            string results = string.Empty;
            foreach (var s in list)
            {
                results += s + ",";
            }
            Console.WriteLine("Autocomplete app = " + results);
        }

    }
}
    
