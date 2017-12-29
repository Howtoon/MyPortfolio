/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphingAPI;

/**
 *
 * @author Howtoon
 */
public class Edge {
	
    private final int fromVertexIndex;
    private final String fromVertexName;
    private final int toVertexIndex;
    private final String toVertexName;
    private final int weight;

    public int getFromVertexIndex() 
    {
        return fromVertexIndex;
    }

    public String getFromVertexName()
    {
        return fromVertexName;
    }

    public int getToVertexIndex() 
    {
        return toVertexIndex;
    }  

    public String getToVertexName()
    {
        return toVertexName;
    }    

    public int getWeight() 
    {
        return weight;
    }

    /**
     * The Index of the starting vertex must be ZERO
     * Determines the neighboring vertex of a supplied vertex, based on the 2 vertices connected by this edge.
     *
     * @param _fromVertexName The Name of the Vertex that the edge starts from.
     * @param _fromVertexIndex The Index of the Vertex that the edge starts from.
     * @param _toVertexName The Name of the Vertex that the edge ends at.
     * @param _toVertexIndex The Index of the Vertex that the edge ends at.
     * @param _weight The cost of traversing the edge.
     */
    public Edge(String _fromVertexName, int _fromVertexIndex, String _toVertexName, int _toVertexIndex, int _weight) 
    {
        this.fromVertexIndex = _fromVertexIndex;
        this.fromVertexName = _fromVertexName;
        this.toVertexIndex = _toVertexIndex;
        this.toVertexName = _toVertexName;
        this.weight = _weight;
    }

    /**
     * Determines the neighboring node of a supplied node, based on the 2 nodes connected by this edge.
     * 
     * @param _vertexIndex
     * @return The index of the neighboring node.
     *
     */
    public int getNeighbourIndex(int _vertexIndex) 
    {
        if (this.fromVertexIndex == _vertexIndex) 
        {
            return this.toVertexIndex;
        } else 
        {
            return this.fromVertexIndex;
        }
    }
			
}
