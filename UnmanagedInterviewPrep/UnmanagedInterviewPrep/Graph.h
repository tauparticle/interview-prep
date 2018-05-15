#pragma once
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
	vector<Node*> neighbors;
};


Node * CloneGraph(Node * graph)
{
	map<Node*,Node*> nodeMap;

	queue<Node*> q;
	q.push(graph);

	Node * graphCopy = new Node();
	nodeMap[graph] = graphCopy;

	while (!q.empty()) 
	{
		Node * node = q.front();
		q.pop();
		int n = node->neighbors.size();
		for (int i = 0; i < n; i++) {
			Node * neighbor = node->neighbors[i];
			// no copy exists
			if (nodeMap.find(neighbor) == nodeMap.end()) {
				Node *p = new Node();
				nodeMap[node]->neighbors.push_back(p);
				nodeMap[neighbor] = p;
				q.push(neighbor);
			} else {     // a copy already exists
				nodeMap[node]->neighbors.push_back(nodeMap[neighbor]);
			}
		}
	}

	return graphCopy;
}

