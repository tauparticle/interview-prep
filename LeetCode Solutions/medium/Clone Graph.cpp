/*133. Clone Graph   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 88840
 Total Submissions: 355609
 Difficulty: Medium
 Contributors: Admin
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 
 OJ's undirected graph serialization:
 Nodes are labeled uniquely.
 
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 
 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 
 */


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> mapping;
        return cloneGraphHelper(node, mapping);
    }
    
    UndirectedGraphNode* cloneGraphHelper(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& mapping)
    {
        if (!node)
        {
            return node;
        }
        
        auto clone = new UndirectedGraphNode(node->label);
        mapping[node->label] = clone;
        for (auto n : node->neighbors)
        {
            auto iter = mapping.find(n->label);
            if (iter != mapping.end())
            {
                clone->neighbors.push_back(iter->second);
            }
            else
            {
                clone->neighbors.push_back(cloneGraphHelper(n, mapping));
            }
        }
        
        return clone;
    }
    
    
};
