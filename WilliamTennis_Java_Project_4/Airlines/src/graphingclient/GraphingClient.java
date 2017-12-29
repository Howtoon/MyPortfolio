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
            new Edge("Chicago", 0, "Miami", 2, 120),
            new Edge("Chicago", 0, "Los Angeles", 3, 90),
            new Edge("Chicago", 0, "Las Vegas", 4, 60),
            new Edge("Chicago", 0, "New York", 1, 60),
            new Edge("New York", 1, "Los Angeles", 3, 240),
            new Edge("New York", 1, "Las Vegas", 4, 180),
            new Edge("New York", 1, "Pensacola", 5, 120),
            new Edge("Miami", 2, "Las Vegas",4, 120),
            new Edge("Los Angeles", 3, "Pensacola", 5, 240),
            new Edge("Las Vegas", 4,"Pensacola", 5, 180),
            new Edge("Las Vegas", 4,"Richmond", 6, 180),
            new Edge("Las Vegas", 4,"Destin", 7, 120),
            new Edge("Pensacola", 5, "Richmond", 6, 120),
            new Edge("Richmond", 6, "Destin",7, 120)
        };
        Graph graph = new Graph(edges, 30);
        graph.calculateShortestDistances();
    }
    
}
