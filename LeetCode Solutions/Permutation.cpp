/* Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int>> results;
        if (num.size() == 0) 
        {
            results.push_back(num);
            return results;
        }
        
        int prefix = num[0];
        vector<int> suffix(++num.begin(), num.end());
        vector<vector<int>> subPerm = permute(suffix);
        for(int i=0; i<subPerm.size(); ++i) 
        {
            int len = subPerm[i].size();
            // insert prefix around every element in list
            for(int j=0; j<=len; ++j) 
            {
                results.push_back(injectNumAtIndex(subPerm[i], prefix, j));
            }
        }
        return results;
    }
    
    vector<int> injectNumAtIndex(vector<int>& list, int num, int pos) {
        vector<int> ret;
        for (int i=0; i<pos; ++i) {
            ret.push_back(list[i]);
        }
        ret.push_back(num);
        
        for (int i=pos; i<list.size(); ++i) {
            ret.push_back(list[i]);
        }
        return ret;    
    }
};