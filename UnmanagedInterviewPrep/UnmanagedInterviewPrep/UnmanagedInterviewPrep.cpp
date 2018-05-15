// interview_prep_unmanaged.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringUtil.h"
#include "LongestIncreasingSequence.h"
#include "VectorOfVectors.h"
#include "LongestSubstring.h"
#include "Permutation.h"
#include "Trie.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	///// Write an algorithm to reverse a c-style string
	//StringUtil util;
	//char s[256] = { "Balloon\0" };
	//util.reverseString(s);
	//std::cout << s << " -> " << s << std::endl;
	//util.reverseString(s);
	//std::cout << s << " -> " << s << std::endl;
	//int arr[10] = { 10, 3, 5, 6, 9, 12, 3, 33, 42, 1 };
	//int longestSequence = util.LongestIncreasingSequence(arr, 10);
	//std::cout << "longest sequence = " << longestSequence << std::endl;

	//longestSequence = util.longestIncreasingSequenceWithDp(arr, 10);
	//std::cout << "longest sequence with DP = " << longestSequence << std::endl;

	//LongestIncreasingSequence lis;
	//std::vector<int> v, o;
	//v.push_back(10); v.push_back(3); v.push_back(5); v.push_back(6); v.push_back(9); v.push_back(12); v.push_back(3); v.push_back(33); v.push_back(42); v.push_back(1);
	//lis.LIS(v, o);

	//std::cout << "Longest increasing sequence = ";
	//for (size_t i = 0; i<o.size(); i++)
	//{
	//	cout << o[i] << "->";
	//}
	//cout << endl;

	//int len = util.longestIncreasingSequenceWithDp(v, v.size(), o);
	//std::cout << "Longest increasing sequence = ";
	//for (size_t i = 0; i<o.size(); i++)
	//{
	//	cout << o[i] << "->";
	//}
	//cout << endl;


	//VectorOfVectorsTest vt;
	//vt.Test();

	//LongestSubstring::Test();

    //TestPermutation::Run();

	TrieTester::Test();

	int a = 5;
	return 0;
}

