#pragma once
#include <vector>

using namespace std;

class NWayMerge
{
public:
	NWayMerge(void);
	~NWayMerge(void);

	vector<int> merge(vector<vector<int>> & allLists);
};

