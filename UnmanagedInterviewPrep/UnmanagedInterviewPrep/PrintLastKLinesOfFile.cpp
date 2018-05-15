#include "stdafx.h"
#include "PrintLastKLinesOfFile.h"
#include <iostream>

using namespace std;
PrintLastKLinesOfFile::PrintLastKLinesOfFile(string & fileName)
{
	/*
	const int K = 10;
 	ifstream file(fileName.c_str());
	string L[K];
	int size = 0;

	while (file.good())
	{
		getline(file, L[size % K]);
		size++;
	}

	int start = size > K ? (size % K) : 0;
	int count = min(K, size);

	for(int i=0; i<count; ++i)
	{
		cout << L[(start + i) % K] << endl;
	}
	*/
}


PrintLastKLinesOfFile::~PrintLastKLinesOfFile(void)
{
}
