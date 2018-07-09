//
// Created by forall on 14.05.18.
//

#ifndef PROJECT_ORIGINAL_NODE_H
#define PROJECT_ORIGINAL_NODE_H

#include <string>
#include "Edge.h"
#include "List.hpp"

class Edge;

class Node {
public:
    Node(std::string key, int x, int y);
    ~Node();
    std::string getKey();
    int getPositionX();
    int getPositionY();
    Liste<Edge*> getEdges();
    void setKey(std::string newKey);
    void setPositionX(int x);
    void setPositionY(int y);
    void setNewEdge(Edge *edge);
private:
    std::string nodeKey;
    int positionX, positionY, id;
    Liste<Edge*> edges;
};


#endif //PROJECT_ORIGINAL_NODE_H
