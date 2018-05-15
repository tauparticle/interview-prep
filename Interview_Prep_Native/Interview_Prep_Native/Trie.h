//
//  Trie.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 8/31/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include <unordered_map>

class TrieNode
{
    public:
    
    TrieNode(char c)
    : m_val(c)
    , m_isLeaf(false)
    {
    }
    
    ~TrieNode()
    {
        for (auto kvp : m_children)
        {
            delete kvp.second;
        }
    }
    
    void insert(std::string& word, int index)
    {
        if (index >= word.length())
        {
            return;
        }
        
        if (index == word.length()-1)
        {
            m_isLeaf = true;
            return;
        }
        
        char c = word[index];
        if (m_children.find(c) == m_children.end())
        {
            m_children[c] = new TrieNode(c);
        }
        
        m_children[c]->insert(word, index + 1);
    }
    
    bool search(std::string& word, int index, bool leafRequired)
    {
        if (index >= word.length())
        {
            return false;
        }
        
        if (index == word.length()-1)
        {
            return leafRequired ? m_isLeaf : true;
        }
        
        int c = word[index];
        
        if (m_children.find(c) == m_children.end())
        {
            return false;
        }
        
        return m_children[c]->search(word, index + 1, leafRequired);
    }
    
    private:
    
    bool m_isLeaf;
    int m_val;
    
    std::unordered_map<char, TrieNode*> m_children;
};

class Trie
{
    public:
    
    Trie()
    {
        m_root = new TrieNode('*');
    }
    
    ~Trie()
    {
        delete m_root;
    }
    
    void addWord(std::string& word)
    {
        if (word.length() == 0)
        {
            return;
        }
        
        m_root->insert(word, 0);
    }
    
    bool searchWord(std::string& word)
    {
        return m_root->search(word, 0, true);
    }
    
    bool searchPrefix(std::string& word)
    {
        return m_root->search(word, 0, false);
    }
    
    private:
    
    TrieNode* m_root;
};



#endif /* Trie_h */
