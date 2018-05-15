#pragma once

#include <vector>
using namespace std;
class StringUtil
{
public:
	StringUtil(void);
	~StringUtil(void);

	void reverseString(char * s);

	int LongestIncreasingSequence(int arr[], int n);

	int longestIncreasingSequenceWithDp( int arr[], int n );

	int longestIncreasingSequenceWithDp( vector<int> & arr, int n, vector<int> & sequence);

private:

	int doLongestIncreasingSequence( int arr[], int n, int *max_ref);
};

