#ifndef PROJECT_ORIGINAL_NAVIGATOR_H
#define PROJECT_ORIGINAL_NAVIGATOR_H

#include "DiGraph.h"
#include "PriorityQueue.hpp"

class Navigator {
public:
    Navigator(DiGraph *graph);

    Liste<Edge *> planRoute(std::string point1Key, std::string point2Key);

    float getRouteDistance(Liste<Edge *> path);

private:
    DiGraph *graph;
    int used;

    int indexOf(Node *n);

    PriorityQueue<Node *> *prioQueNode;
    Liste<Node *> nodes;
};

Navigator::Navigator(DiGraph *graph) {
    this->graph = graph;
    used = graph->getNodes().size();
    prioQueNode = new PriorityQueue<Node *>();
    nodes = graph->getNodes();
}

int Navigator::indexOf(Node *n) {
    for (int j = 0; nodes.size(); j++) {
        if (nodes.getValueAt(j)->getKey() == n->getKey()) {
            return j;
        }
    }

    return -1;
}

Liste<Edge *> Navigator::planRoute(std::string point1Key, std::string point2Key) {
    Node *startNode;
    Node *endNode;
    Node *currentNode;
    Node *previousNode[used];
    float dist[used];
    Node *u;
    Liste<Edge *> result;

    for (int i = 0; i < used; i++) {
        currentNode = nodes.getValueAt(i);

        if (currentNode->getKey() == point1Key)
            startNode = currentNode;

        if (currentNode->getKey() == point2Key)
            endNode = currentNode;
    }

    for (int i = 0; i < used; i++) {
        if (nodes.getValueAt(i) == startNode)
            dist[i] = 0;
        else
            dist[i] = std::numeric_limits<float>::max();

        previousNode[i] = nullptr;

        prioQueNode->insert(nodes.getValueAt(i), dist[i]);
    }

    while (prioQueNode->getSize() > 0) {
        u = prioQueNode->extractMin();
        Liste<Edge *> outEdges = u->getEdges();
        int size = outEdges.size();

        for (int i = 0; i < size; i++) {
            Node *v = outEdges.getValueAt(i)->getEndNode();
            float alt = dist[indexOf(u)] + outEdges.getValueAt(i)->getWeight();

            if (alt < dist[indexOf(v)]) {
                dist[indexOf(v)] = alt;
                previousNode[indexOf(v)] = u;
                prioQueNode->decreaseKey(v, alt);
            }
        }
    }

    u = endNode;

    while (previousNode[indexOf(u)] != nullptr) {
        Liste<Edge *> edges = previousNode[indexOf(u)]->getEdges();

        for (int i = 0; i < edges.size(); i++) {
            if (edges.getValueAt(i)->getEndNode() == u)
                result.append(edges.getValueAt(i));
        }

        u = previousNode[indexOf(u)];
    }

    return result;
}

float Navigator::getRouteDistance(Liste<Edge *> path) {
    float distance = 0;

    for (int i = 0; i < path.size(); i++) {
        distance += path.getValueAt(i)->getWeight();
    }

    return distance;
}

#endif //PROJECT_ORIGINAL_NAVIGATOR_H
