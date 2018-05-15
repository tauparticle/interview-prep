using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep.Graph
{
    public static class DeepCopyGraph
    {
        public static void Test()
        {
            Graph g = GraphHelper.createNewGraph();
            
        }

        public static GraphNode CloneGraph(GraphNode g)
        {
            Dictionary<GraphNode, GraphNode> map = new Dictionary<GraphNode, GraphNode>();

            Queue<GraphNode> q = new Queue<GraphNode>();
            q.Enqueue(g);

            GraphNode graphCopy = new GraphNode(g.getVertex(), g.adjacentCount);
            map[g] = graphCopy;

            while (q.Count > 0)
            {
                GraphNode node = q.Dequeue();

                foreach (GraphNode v in node.getAdjacent())
                {
                    if (!map.ContainsKey(v))
                    {
                        // no copy exists
                        GraphNode p = new GraphNode(v.getVertex(), v.adjacentCount);
                        node.addAdjacent(p);
                        map[v] = p;
                        q.Enqueue(v);
                    }
                    else
                    {
                        // copy already existing
                        map[node].addAdjacent(map[v]);
                    }
                }
            }

            return graphCopy;
        }
    }
}
