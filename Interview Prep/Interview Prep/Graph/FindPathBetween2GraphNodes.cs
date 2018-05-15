using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Graph
{
    public static class FindPathBetween2GraphNodes
    {
        public static void Test()
        {
            Graph g = GraphHelper.createNewGraph();

            GraphNode[] n = g.getNodes();
            GraphNode start = n[3];
            GraphNode end = n[5];

            Console.WriteLine("Find path between {0} and {1}", start.getVertex(), end.getVertex());
            foreach (GraphNode a in FindPath(g, start, end))
            {
                Console.Write(a.getVertex() + "->");
            }
        }

        public static LinkedList<GraphNode> FindPath(Graph g, GraphNode a, GraphNode b)
        {
            if (g == null || a == null || b == null) return null;

            LinkedList<GraphNode> results = new LinkedList<GraphNode>();
            foreach (GraphNode v in g.getNodes())
            {
                v.state = State.Unvisited;
            }

            if (!DepthFirstPathFind(a, b, results))
            {
                results.Clear();
            }

            return results;
        }

        public static bool DepthFirstPathFind(GraphNode graphNode, GraphNode target, LinkedList<GraphNode> path)
        {
            if (graphNode == null) return false;

            // Add this GraphNode to the back of our path
            path.AddLast(graphNode);

            if (graphNode == target)
            {
                return true;
            }

            graphNode.state = State.Visiting;
            
            foreach (GraphNode v in graphNode.getAdjacent())
            {
                if (v.state == State.Unvisited)
                {
                    return DepthFirstPathFind(v, target, path);
                }
            }

            // no path found.  Pop the back of the path 
            path.RemoveLast();
            return false;
        }
    }
}
