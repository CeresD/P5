//
// Created by forall on 14.05.18.
//

#ifndef PROJECT_ORIGINAL_EDGE_H
#define PROJECT_ORIGINAL_EDGE_H

class Node;

class Edge {
public:
    Edge();
    ~Edge();
    float getWeight();
    Node *getStartNode();
    Node *getEndNode();
    void setWeight(float w);
    void setStartNode(Node *node);
    void setEndNode(Node *node);
private:
    Node *startNode, *endNode;
    float weight;
};


#endif //PROJECT_ORIGINAL_EDGE_H
