/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphingAPI;

import java.util.ArrayList;
/**
 *
 * @author Howtoon
 */
public class Graph
{
    private final Vertex[] vertices;
    private final int noOfVertices;
    private final Edge[] edges;
    private final int noOfEdges;
    private int startIndex;
    private int endIndex;

    public Vertex[] getVertices() 
    {
        return vertices;
    }

    public int getNoOfVertices() 
    {
        return noOfVertices;
    }

    public Edge[] getEdges() 
    {
        return edges;
    }

    public int getNoOfEdges() 
    {
        return noOfEdges;
    }

    private final int layoverTime;

    /**
     * Constructor that builds the whole graph from an Array of Edges
     * @param edges An array of edges that is all connections between vertices.
     * @param layoverTime The amount of time added for traversing over a vertex.
     */
    public Graph(Edge[] edges, int layoverTime)
    {
        this.edges = edges;
        this.layoverTime = layoverTime;
        this.noOfVertices = calculateNoOfNodes(edges);
        this.vertices = new Vertex[this.noOfVertices];
        for (int n = 0; n < this.noOfVertices; n++) 
        {
            this.vertices[n] = new Vertex();
        }
        this.noOfEdges = edges.length;
        for (int edgeToAdd = 0; edgeToAdd < this.noOfEdges; edgeToAdd++)
        {
            this.vertices[edges[edgeToAdd].getFromVertexIndex()].getEdges().add(edges[edgeToAdd]);
            this.vertices[edges[edgeToAdd].getFromVertexIndex()].setName(edges[edgeToAdd].getFromVertexName());
            this.vertices[edges[edgeToAdd].getToVertexIndex()].getEdges().add(edges[edgeToAdd]);
            this.vertices[edges[edgeToAdd].getToVertexIndex()].setName(edges[edgeToAdd].getToVertexName());
        }
    }

    /**
     * Calculate the number of Vertices in an array of edges
     * 
     * @param edges An array of edges that represents the graph.
     * @return The number of vertices in the graph.
     *
     */
    private int calculateNoOfNodes(Edge[] edges) 
    {
        int noOfVertices = 0;
        for (Edge e:edges ) 
        {
            if (e.getToVertexIndex() > noOfVertices) noOfVertices = e.getToVertexIndex();
            if (e.getFromVertexIndex() > noOfVertices) noOfVertices = e.getFromVertexIndex();
        }
        noOfVertices++;	
        return noOfVertices;		
    }

    /**
     * Uses Dijkstra's algorithm to calculate the shortest distance from the source to all vertexes in the graph
     * 
     */
    public void calculateShortestDistances() 
    {   
        this.vertices[0].setDistanceFromSource(0);
        int nextVertex = this.startIndex;

        for(int i = 0; i < this.vertices.length; i++) 
        {
            //System.out.println("NextVertex: "+this.vertices[nextVertex].getName());
            ArrayList<Edge> currentVertexEdges = this.vertices[nextVertex].getEdges();
            for (int adjacentEdge = 0; adjacentEdge < currentVertexEdges.size(); adjacentEdge++) 
            {

                int neighbourIndex = currentVertexEdges.get(adjacentEdge).getNeighbourIndex(nextVertex);
                //System.out.println("NeighborIndex: "+this.vertices[neighbourIndex].getName());
                if (!this.vertices[neighbourIndex].isVisited()) 
                {
                    int tentative = this.vertices[nextVertex].getDistanceFromSource() + currentVertexEdges.get(adjacentEdge).getWeight() + this.layoverTime;
                    
                    if (tentative < vertices[neighbourIndex].getDistanceFromSource()) 
                    {
                            vertices[neighbourIndex].setDistanceFromSource(tentative);
                    }
                }
            }
            vertices[nextVertex].setVisited(true);
            nextVertex = getNodeShortestDistance();
        }
        System.out.println(getString());
    }

    private int getVertexIndex(String vertexName)
    {
        int index = 0;
        
        for (int i = 0; i < this.vertices.length; i++)
        {
            if (this.vertices[i].getName().compareToIgnoreCase(vertexName)==0)
            {
                index = i;
            }
        }
        System.out.println("Index of "+vertexName+" is "+index);
        return index;
    }
    
    private int getNodeShortestDistance() 
    {
        int storedVertexIndex = 0;
        int storedDist = Integer.MAX_VALUE;

        for (int i = 0; i < this.vertices.length; i++) 
        {
            int currentDist = this.vertices[i].getDistanceFromSource();			
            if (!this.vertices[i].isVisited() && currentDist < storedDist) 
            {
                storedDist = currentDist;
                storedVertexIndex = i;
            }
        }
        return storedVertexIndex;
    }

    /**
     *Shows the contents of the graph
     * 
     * @return a String that shows the shortest length to all vertices
     */
    private String getString() 
    {
        String output = "";
        for (int i = 1; i < this.vertices.length; i++) 
        {
            output += ("The shortest distance from "+this.vertices[this.startIndex].getName()+ " to " + this.vertices[i].getName() + " is "+(vertices[i].getDistanceFromSource()-this.layoverTime)+"\n");
        }
        return output;
    }
}