// OneEditDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

bool isSingleEdit(std::string & s, std::string& t)
{
	int diff = 0;
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] != t[i])
		{
			if (++diff > 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool isSingleInsert(std::string & s, std::string & t)
{
	// s is always larger, so just look for insert
	int shift = 0;
	size_t i = 0; 
	size_t j = 0;

	while (i < s.length())
	{
		if (s[i] == t[j])
		{
			i++; 
			j++;
		}
		else
		{
			if (++shift > 1)
			{
				return false;
			}			
			i++;
		}
	}
	return true;
}

bool isOneEditDistance(std::string s, std::string t)
{
	int m = s.length();
	int n = t.length();
	if (m < n)
	{
		return isOneEditDistance(t, s);
	}

	if ((m-n) > 1)
	{
		return false;
	}

	if (n == m)
	{
		return isSingleEdit(s, t);
	}

	return isSingleInsert(s, t);
}



int _tmain(int argc, _TCHAR* argv[])
{
	std::string a = "abcde";
	std::string b = "abXde";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;

    a = "abcde";
	b = "abcXde";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;

	a = "abcde";
	b = "abcdeX";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;

	a = "abcde";
	b = "Xabcde";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;

	a = "abcde";
	b = "XabcDde";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;

	a = "abcde";
	b = "bcdea";

	std::cout << a << ", " << b << " = " << isOneEditDistance(a, b) << std::endl;
	return 0;
}

