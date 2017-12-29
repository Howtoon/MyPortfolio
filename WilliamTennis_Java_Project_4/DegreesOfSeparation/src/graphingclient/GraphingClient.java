/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package graphingclient;

import graphingAPI.Edge;
import graphingAPI.Graph;

/**
 *
 * @author Howtoon
 */
public class GraphingClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Edge[] edges =
        {	
            new Edge("Mike", 0, "Haley", 2, 1),
            new Edge("Mike", 0, "John", 3, 1),
            new Edge("Mike", 0, "Ashley", 4, 1),
            new Edge("Mike", 0, "George", 1, 1),
            new Edge("George", 1, "John", 3, 1),
            new Edge("George", 1, "Ashley", 4, 1),
            new Edge("George", 1, "Penelope", 5, 1),
            new Edge("Haley", 2, "Ashley",4, 1),
            new Edge("John", 3, "Penelope", 5, 1),
            new Edge("Ashley", 4,"Penelope", 5, 1),
            new Edge("Ashley", 4,"Richmond", 6, 1),
            new Edge("Ashley", 4,"Duncan", 7, 1),
            new Edge("Penelope", 5, "Richard", 6, 1),
            new Edge("Richard", 6, "Duncan",7, 1)
        };
        Graph graph = new Graph(edges, 1);
        graph.calculateShortestDistances();
    }
    
}
