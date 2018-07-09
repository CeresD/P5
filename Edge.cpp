//
// Created by forall on 14.05.18.
//

#include "Edge.h"

Edge::Edge() {
    startNode = nullptr;
    endNode = nullptr;
}

Edge::~Edge() {
    delete startNode;
    delete endNode;
}

float Edge::getWeight() {
    return weight;
}

Node *Edge::getStartNode() {
    return startNode;
}

Node *Edge::getEndNode() {
    return endNode;
}

void Edge::setWeight(float w) {
    weight = w;
}

void Edge::setStartNode(Node *node) {
    startNode = node;
}

void Edge::setEndNode(Node *node) {
    endNode = node;
}
