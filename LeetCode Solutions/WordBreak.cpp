/* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:

    // this is O(n^2) DP solution since each call iterates through a reducing set of characters and splits the work in 2 each time
    // The memory is O(n) due to the string creation and recursion
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        if (dict.find(s) != dict.end()) {
            return true;
        }
        
        if (m_cache.find(s) != m_cache.end())
        {
            return m_cache[s];
        }
        
        for (int i=1; i<s.size(); ++i) {
            
         string prefix = s.substr(0, i);
         if (dict.find(prefix) != dict.end()) {
                
                string suffix = s.substr(i);
                
                if (wordBreak(suffix, dict)) {
                    m_cache[s] = true;
                    return true;
                }
            }
        }
        m_cache[s] = false;
        return false;

    }
    
private:
    
    map<string, bool> m_cache;
};
