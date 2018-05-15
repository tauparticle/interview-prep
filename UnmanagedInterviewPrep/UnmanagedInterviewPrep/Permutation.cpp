#include "stdafx.h"
#include "Permutation.h"



Permutation::Permutation()
{
}


Permutation::~Permutation()
{
}

vector<vector<int>> Permutation::permute(vector<int> &num) {

    vector<vector<int>> results;
    if (num.size() == 0)
    {
        results.push_back(num);
        return results;
    }

    int prefix = num[0];
    vector<int> suffix(++num.begin(), num.end());
    vector<vector<int>> subPerm = permute(suffix);
    for (int i = 0; i<subPerm.size(); ++i)
    {
        int len = subPerm[i].size();
        if (len == 0)
        {
            // special case for empty list
            results.push_back(injectNumAtIndex(subPerm[i], prefix, 0));
        }
        else
        {
            // general case, insert prefix around every element in list
            for (int j = 0; j<=len; ++j)
            {
                results.push_back(injectNumAtIndex(subPerm[i], prefix, j));
            }
        }
    }

    return results;
}


vector<int> Permutation::injectNumAtIndex(vector<int>& list, int num, int pos) {
    vector<int> ret;
    for (int i = 0; i < pos; ++i) {
        ret.push_back(list[i]);
    }
    ret.push_back(num);

    for (int i = pos; i < list.size(); ++i) {
        ret.push_back(list[i]);
    }
    return ret;
}
