//
//  AlienDictionary.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 2/12/17.
//  Copyright © 2017 poot industries. All rights reserved.
//

#ifndef AlienDictionary_h
#define AlienDictionary_h


#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>

using namespace std;

class AlienDictionary
{
public:
    
    string decode(vector<string>& words)
    {
        createGraph(words);
        return topologicalSort();
    }
    
    
protected:
    
    void createGraph(vector<string>& words)
    {
        for (int i=0; i<words.size()-1; ++i)
        {
            string& word1 = words[i];
            string& word2 = words[i+1];
            
            size_t size = min(word1.size(), word2.size());
            for (int j=0; j<size; ++j)
            {
                if (word1[j] != word2[j])
                {
                    auto& set = m_adjList[word1[j]];
                    set.insert(word2[j]);
                }
            }
        }
        
        for (auto iter = m_adjList.begin(); iter != m_adjList.end(); ++iter)
        {
            cout << "v: " << iter->first << " -> ";
            for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
            {
                cout << *it << ",";
            }
            cout << endl;
        }
    }
    
    string topologicalSort()
    {
        stack<char> s;
        unordered_set<char> visited;
        
        for (auto it = m_adjList.begin(); it != m_adjList.end(); ++it)
        {
            char v = it->first;
            if (visited.find(v) == visited.end())
            {
                topologicalSortDfs(v, visited, s);
            }
        }
        
        ostringstream oss;
        while (!s.empty())
        {
            oss << s.top();
            s.pop();
        }
        return oss.str();
    }
    
    void topologicalSortDfs(char v, unordered_set<char>& visited, stack<char>& s)
    {
        visited.insert(v);
        
        auto it = m_adjList.find(v);
        if (it != m_adjList.end())
        {
            auto& neighbors = it->second;
            for (auto iter = neighbors.begin(); iter != neighbors.end(); ++iter)
            {
                char c = *iter;
                if (visited.find(c) == visited.end())
                {
                    topologicalSortDfs(c, visited, s);
                }
            }
        }
        
        s.push(v);
    }
    
    unordered_map<char, unordered_set<char>> m_adjList;
};

#endif /* AlienDictionary_h */
