//
// Created by forall on 14.05.18.
//

#include "Node.h"

Node::Node(std::string key, int x, int y) {
    nodeKey = key;
    positionX = x;
    positionY = y;
}

Node::~Node() {
    while (edges.size() > 0) {
        edges.remove(edges.getValueAt(0));
    }
}

std::string Node::getKey() {
    return nodeKey;
}

int Node::getPositionX() {
    return positionX;
}

int Node::getPositionY() {
    return positionY;
}

Liste<Edge *> Node::getEdges() {
    return edges;
}

void Node::setKey(std::string newKey) {
    nodeKey = newKey;
}

void Node::setPositionX(int x) {
    positionX = x;
}

void Node::setPositionY(int y) {
    positionY = y;
}

void Node::setNewEdge(Edge *edge) {
    edges.append(edge);
}