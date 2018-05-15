#include "stdafx.h"
#include "LongestIncreasingSequence.h"
LongestIncreasingSequence::LongestIncreasingSequence(void) {}
LongestIncreasingSequence::~LongestIncreasingSequence(void) {}

void LongestIncreasingSequence::LIS(const vector<int> & input, vector<int> & output)
{
	output.clear();
	if (input.size() == 0)
	{
		return;
	}

	vector<int> lisLength(input.size(), 1);
	vector<int> previousIndex(input.size(), -1);

	int maxLength = 1;
	int longestSequenceEnd = 0;

	int iterationCount = 0;
	for (int i=1; i<input.size(); i++)
	{
		int length = 1;
		int prevIndex = -1;
		for (int j=0; j<i; j++)
		{
			iterationCount++;
			if (input[i] > input[j]  && lisLength[j] + 1 > length)
			{
				length = lisLength[j]+1;
				prevIndex = j;
			}
		}

		lisLength[i] = length;
		previousIndex[i] = prevIndex;

		if (maxLength < length)
		{
			maxLength = length;
			longestSequenceEnd = i;
		}
	}

	while (longestSequenceEnd >= 0)
	{
		output.push_back(input[longestSequenceEnd]);
		longestSequenceEnd = previousIndex[longestSequenceEnd];
	}

	std::reverse(output.begin(), output.end());
}
