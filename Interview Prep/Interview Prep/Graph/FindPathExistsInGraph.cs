using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Graph
{
    public static class FindPathExistsInGraph
    {
        public static void Test()
        {
            Graph g = GraphHelper.createNewGraph();

            GraphNode[] n = g.getNodes();
            GraphNode start = n[3];
            GraphNode end = n[5];

            Console.WriteLine("\nBFS {0}, {1} = {2}", start.getVertex(), end.getVertex(), BreadthFirstSearch(g, start, end));

            start = n[3];
            end = n[5];
            Console.WriteLine("\nDFS {0}, {1} = {2}", start.getVertex(), end.getVertex(), DepthFirstSearch(g, start, end));
        }

        public static bool DepthFirstSearch(Graph g, GraphNode a, GraphNode b)
        {
            if (g == null || a == null || b == null) return false;
            foreach (GraphNode n in g.getNodes())
            {
                n.state = State.Unvisited;
            }
            return DoDfs(a, b);
        }

        public static bool DoDfs(GraphNode a, GraphNode b)
        {
            if (a == null || b == null)
            {
                return false;
            }

            if (a == b)
            {
                return true;
            }

            a.state = State.Visiting;
    
            foreach (GraphNode v in a.getAdjacent())
            {
                if (v.state == State.Unvisited)
                {
                    return DoDfs(v, b);
                }
            }
            
            a.state = State.Visited;
            return false;
        }



        public static bool BreadthFirstSearch(Graph g, GraphNode a, GraphNode b)
        {
            if (g == null || a == null || b == null) return false;
            Queue<GraphNode> q = new Queue<GraphNode>();
            foreach (GraphNode n in g.getNodes())
            {
                n.state = State.Unvisited;
            }

            q.Enqueue(a);
            a.state = State.Visiting;

            while (q.Count != 0)
            {
                GraphNode n = q.Dequeue();
                if (n != null)
                {
                    foreach (GraphNode v in n.getAdjacent())
                    {
                        if (v.state == State.Unvisited)
                        {
                            if (v == b)
                            {
                                return true;
                            }
                            else
                            {
                                v.state = State.Visiting;
                                q.Enqueue(v);
                            }
                        }
                    }
                    n.state = State.Visited;
                }
            }
            return false;
        }
    }
}
