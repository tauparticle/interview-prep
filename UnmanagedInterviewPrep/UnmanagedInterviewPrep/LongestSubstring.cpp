#include "stdafx.h"
#include "LongestSubstring.h"
#include <iostream>

void LongestSubstring::Test()
{
	string s = "ask not what your country can do for you but what you can do for your country";

	string longestSubstr = FindLongestRepeatedSubString(s);
	cout << "longest Substr = " << longestSubstr << endl;
	int a=5;
}

string LongestSubstring::FindLongestRepeatedSubString(const string & input)
{
	char * suffixArray[256000];
	int maxLen = -1;
	int maxi = -1;

	for (size_t i=0; i<input.size(); ++i)
	{
		suffixArray[i] = (char*)(&input[i]);
	}

	qsort(suffixArray, input.size(), sizeof(char*), qsort_strcmp);

	for(size_t i=0; i<input.size()-1; ++i)
	{
		int thisLen = commonLength(suffixArray[i], suffixArray[i+1]);
		if (thisLen > maxLen)
		{
			maxLen = thisLen;
			maxi = i;
		}
	}

	delete[] suffixArray;
	return string(suffixArray[maxi], maxLen);
}

int LongestSubstring::qsort_strcmp(const void * v1, const void * v2)
{
	const char * s1 = *(char * const *)v1;
	const char * s2 = *(char * const *)v2;
	return strcmp(s1, s2);
}

int LongestSubstring::commonLength(char * a, char * b)
{
	int length = 0;
	while (*a && *a++ == *b++)
	{
		length++;
	}
	return length;
}

