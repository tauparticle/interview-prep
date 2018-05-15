#pragma once
#include <string>

using namespace std;
class LongestSubstring
{
public:
    static void Test();
	static string FindLongestRepeatedSubString(const string & input);

private:
	static int commonLength (char * p, char * q);
	static int qsort_strcmp(const void * v1, const void * v2);

};

