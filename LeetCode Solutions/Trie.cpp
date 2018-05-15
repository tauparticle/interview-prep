class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        m_isLeaf = false;
        m_children = new unordered_map<char, TrieNode*>();
    }
    
    ~TrieNode()
    {
        for (auto iter = m_children->begin(); iter != m_children->end(); ++iter)
        {
            delete iter->second;
        }
        delete m_children;
    }
    
    bool m_isLeaf;
    unordered_map<char, TrieNode*>* m_children;
};

class Trie {
public:
    Trie() {
        m_root = new TrieNode();
    }
    
    ~Trie()
    {
        delete m_root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        
        auto children = m_root->m_children;
        auto node = m_root;
        
        for (int i=0; i<word.size(); ++i)
        {
            char c = word[i];
            auto iter = children->find(c);
            if (iter == children->end())
            {
                node = new TrieNode();
                (*children)[c] = node;
            }
            else
            {
                node = iter->second;
            }
            
            children = node->m_children;
            
            if (i == word.size()-1)
            {
                node->m_isLeaf = true;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        auto node = m_root;
        auto children = m_root->m_children;
        
        for (int i=0; i<word.length(); ++i)
        {
            char c = word[i];
            auto iter = children->find(c);
            if (iter == children->end())
            {
                return false;
            }
            
            node = iter->second;
            children = node->m_children;
        }
        
        return node->m_isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto node = m_root;
        auto children = m_root->m_children;
        
        for (int i=0; i<prefix.length(); ++i)
        {
            char c = prefix[i];
            auto iter = children->find(c);
            if (iter == children->end())
            {
                return false;
            }
            
            node = iter->second;
            children = node->m_children;
        }
        
        return true;
    }

private:
    TrieNode* m_root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");