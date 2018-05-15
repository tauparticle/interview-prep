
/*
 Given two strings s and t, determine if they are isomorphic.
 
 Two strings are isomorphic if the characters in s can be replaced to get t.
 
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 
 For example,
 Given "egg", "add", return true.
 
 Given "foo", "bar", return false.
 
 Given "paper", "title", return true.
 
 Note:
 You may assume both s and t have the same length.
 
 */


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size() != t.size())
        {
            return false;
        }
        
        map<char, int> charMapS;
        map<char, int> charMapT;
        
        // egg = [[e,0][g,1]]
        // add = [[a,0][d,1]]
        for (int i=0; i<s.size(); ++i)
        {
            charMapS[s[i]] = i;
            charMapT[t[i]] = i;
        }
        
        // compare the last known position of each char in each string
        // if their position is not equal, the string is not isomorphic
        for (int i=0; i<s.size(); ++i)
        {
            if (charMapS[s[i]] != charMapT[t[i]])
            {
                return false;
            }
        }
        return true;
    }
    
    
};