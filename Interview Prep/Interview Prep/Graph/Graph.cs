using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Interview_Prep.Graph;

namespace Interview_Prep.Graph
{
    public enum State
    {
        Unvisited,
        Visited,
        Visiting
    }

    public class GraphNode
    {
        private readonly GraphNode[] adjacent;
        public int adjacentCount;
        private readonly String vertex;
        public State state;

        public GraphNode(String vertex, int adjacentLength)
        {
            this.vertex = vertex;
            adjacentCount = 0;
            adjacent = new GraphNode[adjacentLength];
        }

        public void addAdjacent(GraphNode x)
        {
            if (adjacentCount < 30)
            {
                this.adjacent[adjacentCount] = x;
                adjacentCount++;
            }
            else
            {
                Console.WriteLine("No more adjacent can be added");
            }
        }

        public GraphNode[] getAdjacent()
        {
            return adjacent;
        }

        public String getVertex()
        {
            return vertex;
        }
    }

    public class Graph
    {
        private readonly GraphNode[] vertices;
        public int count;

        public Graph()
        {
            vertices = new GraphNode[6];
            count = 0;
        }

        public void addNode(GraphNode x)
        {
            if (count < 30)
            {
                vertices[count] = x;
                count++;
            }
            else
            {
                Console.Write("Graph full");
            }
        }

        public GraphNode[] getNodes()
        {
            return vertices;
        }

        
        
    }

    public static class GraphHelper
    {
        public static Graph createNewGraph()
        {
            Graph g = new Graph();
            GraphNode[] temp = new GraphNode[6];

            temp[0] = new GraphNode("a", 3);
            temp[1] = new GraphNode("b", 0);
            temp[2] = new GraphNode("c", 0);
            temp[3] = new GraphNode("d", 1);
            temp[4] = new GraphNode("e", 1);
            temp[5] = new GraphNode("f", 0);

            temp[0].addAdjacent(temp[1]);
            temp[0].addAdjacent(temp[2]);
            temp[0].addAdjacent(temp[3]);
            temp[3].addAdjacent(temp[4]);
            temp[4].addAdjacent(temp[5]);
            for (int i = 0; i < 6; i++)
            {
                g.addNode(temp[i]);
            }
            return g;
        }
    }
}
