#pragma once
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class TrieNode {
public:

	typedef map<char, TrieNode*> TriNodeMap;
	TriNodeMap m_children;
	char m_key;
	bool m_terminator;
	// Initialize your data structure here.
	TrieNode(char key, bool terminator) {
		m_terminator = terminator;
		m_key = key;
	}

	~TrieNode()
	{
		TriNodeMap::const_iterator iter;
		for (iter = m_children.begin(); iter != m_children.end(); ++iter)
		{
			delete iter->second;
		}
	}

	TrieNode * GetChild(char key)
	{
		TriNodeMap::const_iterator iter = m_children.find(key);
		if (iter != m_children.end())
		{
			return iter->second;
		}
		return NULL;
	}

	void Insert(char key, string suffix)
	{
		TrieNode * child = GetChild(key);
		if (child == NULL)
		{
			child = new TrieNode(key, suffix.length() == 0);
			m_children[key] = child;
		}

		if (suffix.length() > 0)
		{
			key = suffix[0];
			suffix = suffix.substr(1);
			child->Insert(key, suffix);
		}
		else
		{
			child->m_terminator = true;
		}
	}

	bool Contains(char key, string suffix, bool terminatorRequired = false)
	{
		TrieNode* child = GetChild(key);
		if (!child)
		{
			return false;
		}

		if (suffix.length() > 0)
		{
			key = suffix[0];
			suffix = suffix.substr(1);
			return child->Contains(key, suffix, terminatorRequired);
		}
		else
		{
			if (terminatorRequired)
			{
				return child->m_terminator;
			}
			return true;
		}
	}


};

class Trie 
{
public:
	Trie() {
		root = new TrieNode('?', false);
	}

	// Inserts a word into the trie.
	void insert(string s) {
		if (s.length() > 0)
		{
			char key = s[0];
			string suffix = s.substr(1);
			root->Insert(key, suffix);
		}
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		if (key.length() > 0)
		{
			char c = key[0];
			string suffix = key.substr(1);
			return root->Contains(c, suffix, true);
		}
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		if (prefix.length() > 0)
		{
			char key = prefix[0];
			string suffix = prefix.substr(1);
			return root->Contains(key, suffix);
		}
		return false;
	}

private:
	TrieNode* root;
};

class TrieTester
{
public:
	static void Test()
	{
		Trie t;
		t.insert("abc");
		cout << "search abc = " << t.search("abc") << endl;
		cout << "search ab = " << t.search("ab") << endl;
		t.insert("ab");
		cout << "search ab = " << t.search("ab") << endl;
		t.insert("ab");
		cout << "search ab = " << t.search("ab") << endl;		
	}
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");