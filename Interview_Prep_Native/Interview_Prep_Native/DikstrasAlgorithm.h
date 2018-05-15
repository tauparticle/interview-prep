//
//  DikstrasAlgorithm.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 9/3/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef DikstrasAlgorithm_h
#define DikstrasAlgorithm_h

#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct GraphVertex;

struct Distance
{
    // distance scores and # of edges
    int length = numeric_limits<int>::max();
    int nodeLength = 0;
};

struct Edge
{
    GraphVertex * vertex;
    int weight;
    Edge(GraphVertex* v, int w)
    : vertex(v)
    , weight(w)
    {
    }
};

struct GraphVertex
{
    Distance distance;
    vector<Edge> edges;
    int id;
    // predicessor in the shortest path
    const GraphVertex* predecessor = nullptr;
    
    GraphVertex(int i)
    {
        id = i;
    }
    
};

struct Comp
{
    bool operator()(const GraphVertex * lhs, const GraphVertex * rhs)
    {
        return lhs->distance.length < rhs->distance.length ||
                (lhs->distance.length == rhs->distance.length &&
                 lhs->distance.nodeLength < rhs->distance.nodeLength);
    }
};


class Djikstra
{
    public:
    
    static void PrintOutput(const GraphVertex* v)
    {
        if (v)
        {
            PrintOutput(v->predecessor);
            cout << v->id << " ";
        }
    }
    
    

    static vector<GraphVertex*> PathSearch(GraphVertex * start, GraphVertex * end)
    {
        // initialize distance of starting point
        start->distance.length = 0;
        start->distance.nodeLength = 0;
        
        set<GraphVertex*, Comp> nodeSet;
        
        nodeSet.emplace(start);
        
        while(!nodeSet.empty())
        {
            // extract the minimum distance vertex from the heap
            GraphVertex* u = *nodeSet.cbegin();
            if (u->id == end->id)
            {
                // we're done
                break;
            }
            
            // pop
            nodeSet.erase(*nodeSet.cbegin());
            
            // relax neighboring verticies of u
            for (const auto& v : u->edges)
            {
                int v_distance = u->distance.length + v.weight;
                int v_num_of_edges = u->distance.nodeLength + 1;
                
                if (v.vertex->distance.length > v_distance ||
                    (v.vertex->distance.length == v_distance &&
                     v.vertex->distance.nodeLength > v_num_of_edges))
                {
                    nodeSet.erase(v.vertex);
                    v.vertex->predecessor = u;
                    v.vertex->distance.length = v_distance;
                    v.vertex->distance.nodeLength = v_num_of_edges;
                    nodeSet.emplace(&v.vertex);
                }
            }
        }
        
        PrintOutput(end);
        
        vector<GraphVertex*> path;
        GraphVertex * current = end;
        while (current)
        {
            path.push_back(current);
            current = const_cast<GraphVertex*>(current->predecessor);
        }
        
        std::reverse(path.begin(), path.end());
        return path;
    }
};


#endif /* DikstrasAlgorithm_h */
