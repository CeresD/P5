#include "SFMLGraphVisualizer.h"
#include <iostream>
//#include "Vehicle.hpp"
#include "Navigator.hpp"
#include <thread>

void createDummyGraph(DiGraph &g) {
    g.addNode("Aachen", 100, 600);
    g.addNode("Berlin", 300, 650);
    g.addNode("Koeln", 300, 300);
    g.addNode("Essen", 900, 300);
    g.addNode("Bonn", 300, 150);
    g.addNode("Krefeld", 100, 160);

    g.addEdge("Aachen", "Berlin", 7);
    g.addEdge("Koeln", "Aachen", 9);
    g.addEdge("Aachen", "Krefeld", 7);
    g.addEdge("Berlin", "Essen", 10);
    g.addEdge("Berlin", "Koeln", 12);
    g.addEdge("Koeln", "Essen", 5);
    g.addEdge("Bonn", "Essen", 8);
    g.addEdge("Krefeld", "Bonn", 1);
}

int main() {
    DiGraph myGraph;
    SFMLGraphVisualizer graphvis;
    myGraph.setVisualizer(&graphvis);

    //myGraph.saveGraphToFile("test2.txt");
    myGraph.loadGraphFromFile("test2.txt");

    Navigator navi(&myGraph);
    Liste<Edge *> path = navi.planRoute("Berlin", "Essen");

    graphvis.highlightPath(path);
    graphvis.visualize(myGraph);

    myGraph.saveGraphToFile("test2.txt");
    // std::cout << "Fahrdistanz: " << navi.getRouteDistance(path) << std::endl;
    return 0;
}