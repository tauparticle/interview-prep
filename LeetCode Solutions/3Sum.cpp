/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 Find all unique triplets in the array which gives the sum of zero.

Note:
-Elements in a triplet (a,b,c) must be in non-descending order. 
-The solution set must not contain duplicate triplets.
-For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)

*/

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {

		set<vector<int> > results;
		sort(num.begin(), num.end());
		set<string> uniqueSets;
		int len = num.size();

		for (int i = 0; i<len-2; ++i)
		{
			int a = num[i];
			int start = i + 1;
			int end = len - 1;

			while (start < end)
			{
				int b = num[start];
				int c = num[end];
				int sum = a + b + c;

				if (sum == 0)
				{
					vector<int> set = { a, b, c };
					results.insert(set);
					start++;
					end--;
				}
				else if (sum > 0)
				{
					end--;
				}
				else
				{
					start++;
				}
			}
		}

		return vector<vector<int> >(results.begin(), results.end());;
	}
};


// without using the std::set to keep worst case o(n) memory lower

class Solution {
public:
vector<vector<int> > threeSum(vector<int> &num) {
		vector< vector<int> > vecTriplets;
		vector<int> triplet(3, 0);
		if (num.size() < 3) return vecTriplets;
		sort(num.begin(), num.end());

		int lastIndex = num.size() - 2;
		int j = 0, k = lastIndex + 1;
		for (int i = 0; i < lastIndex; ++i) {
			if (i > 0 && num[i] == num[i - 1])
			    continue ;
			triplet[0] = num[i];
			j = i + 1;
			k = lastIndex + 1;
			while (j < k) {
				if (j > i + 1 && num[j] == num[j - 1]) {
					++j;
					continue ;
				}
				int sum = num[j] + num[k];
				if (num[i] + sum == 0) {
					triplet[1] = num[j++];
					triplet[2] = num[k--];
					vecTriplets.push_back(triplet);
				}
				else if (num[i] + sum > 0) {
					--k;
				}
				else {
					++j;
				} // if (num[i] + sum == 0)
			} // while (i < k)
		} // for (int i)
		return vecTriplets;
    }
        
};