#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Permutation
{
public:
    Permutation();
    ~Permutation();

    vector<vector<int>> permute(vector<int> &num);

private:

    vector<int> injectNumAtIndex(vector<int>& list, int num, int pos);
    
};

class TestPermutation
{

public:
    static void Run()
    {
        Permutation perm;

        vector<int> num { 1, 0 };

        vector<vector<int>> res = perm.permute(num);

        cout << "{0, 1} = " << res.size() << " unique permutation" << endl;
    }
};

