#ifndef PROJECT_ORIGINAL_DIGRAPH_H
#define PROJECT_ORIGINAL_DIGRAPH_H

#include "Node.h"
#include <string>

class Node;
class GraphVisualizer;

class DiGraph {
public:
    DiGraph();
    void addNode(std::string key, int posX, int posY);
    void addEdge(std::string key1, std::string key2, float weight);
    Liste<Node*> getNeightbours(std::string key);
    Liste<Edge*> getEdges(std::string key);
    Liste<Node*> getNodes();
    void setVisualizer(GraphVisualizer* graphvis);
    GraphVisualizer* getVisualizer();
    void saveGraphToFile(std::string path);
    void loadGraphFromFile(std::string path);
private:
    Node **nodes;
    GraphVisualizer* graphvisualizer;
};


#endif //PROJECT_ORIGINAL_DIGRAPH_H
