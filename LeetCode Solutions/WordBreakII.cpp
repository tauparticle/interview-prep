/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].*/

class Solution {
public:

    // this is the absolute best solution
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
        vector<string> ret;
        
        if (m_cache.find(s) != m_cache.end()) {
            return m_cache[s];
        }
        
        if (dict.find(s) != dict.end()) {
            ret.push_back(s);
        }
        
        for(int i=1; i<s.size(); ++i) {
            string prefix = s.substr(0, i);
            string suffix = s.substr(i);
            if ((dict.find(prefix) != dict.end()) && containsSuffix(suffix, dict)) {
                vector<string> segSuffix = wordBreak(suffix, dict);
                for(int j=0; j<segSuffix.size(); ++j) {
                    ret.push_back(prefix + " " + segSuffix[j]);
                }
            }
        }
        m_cache[s] = ret;
        return ret;
    }

private:

    // optimal solution to scan ahead before wasting time on recursive checks
    bool containsSuffix(string & s, unordered_set<string> & dict)
    {
       if (dict.find(s) != dict.end()) {
           return true;
       } 
       
       for (int i=0; i<s.size(); ++i) {
           if (dict.find(s.substr(i)) != dict.end()) {
               return true;
           }
       }
       return false;
    }
    
    map<string, vector<string>> m_cache;
};