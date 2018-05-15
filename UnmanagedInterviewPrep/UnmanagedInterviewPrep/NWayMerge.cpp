#include "stdafx.h"
#include "NWayMerge.h"
#include <queue>
#include <algorithm>


NWayMerge::NWayMerge(void)
{
}


NWayMerge::~NWayMerge(void)
{
}

vector<int> NWayMerge::merge(vector<vector<int>> & allLists)
{
	std::priority_queue<pair<int, int>> q;
	vector<int> mergedList;

	vector<int> listIndicies;
	listIndicies.resize(allLists.size(), 0);

	// O(n)
	for( int i=0; i<allLists.size(); ++i)
	{
		pair<int,int> valuetoIndex = make_pair(allLists[i][listIndicies[i]], listIndicies[i]);
		q.push(valuetoIndex);
		listIndicies[i]++;
	}

	while (!q.empty())
	{
		pair<int,int> top = q.top();
		q.pop();
		mergedList.push_back(top.first);

		pair<int,int> next = make_pair(allLists[top.second][listIndicies[top.second]], top.second);
		listIndicies[top.second]++;
		q.push(next);
	}


	return mergedList;
}
