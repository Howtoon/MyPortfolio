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
public class Vertex {
	
    private int distanceFromSource = Integer.MAX_VALUE;
    private boolean visited = false;
    private ArrayList<Edge> edges = new ArrayList<>();
    private String name;       

    public int getDistanceFromSource() 
    {
        return distanceFromSource;
    }

    public void setDistanceFromSource(int distanceFromSource)
    {
        this.distanceFromSource = distanceFromSource;
    }

    public boolean isVisited()
    {
        return visited;
    }

    public void setVisited(boolean visited) 
    {
        this.visited = visited;
    }

    public ArrayList<Edge> getEdges() 
    {
        return edges;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return this.name;
    }

    public void setEdges(ArrayList<Edge> edges)
    {
        this.edges = edges;
    }

}