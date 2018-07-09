//
// Created by forall on 14.05.18.
//

#include <iostream>
#include "DiGraph.h"
#include <fstream>
#include "tokenizer.hpp"

DiGraph::DiGraph() {
    nodes = new Node *[20];

    for (int i = 0; i < 20; i++) {
        nodes[i] = NULL;
    }
}

void DiGraph::addNode(std::string key, int posX, int posY) {
    int i = 0;

    while (nodes[i]) {
        i++;
    }

    nodes[i] = new Node(key, posX, posY);
}

void DiGraph::addEdge(std::string key1, std::string key2, float weight) {
    Edge *e = new Edge();
    e->setWeight(weight);
    int i = 0;
    Node *startNode;
    Node *endNode;
    bool startNodeExists = false;
    bool endNodeExists = false;

    while (nodes[i]) {
        if (nodes[i]->getKey() == key1) {
            startNode = nodes[i];
            startNodeExists = true;
        }

        if (nodes[i]->getKey() == key2) {
            endNode = nodes[i];
            endNodeExists = true;
        }

        if (startNodeExists && endNodeExists)
            break;

        i++;
    }

    if (startNodeExists || endNodeExists) {
        e->setStartNode(startNode);
        e->setEndNode(endNode);
        startNode->setNewEdge(e);
    }

}

Liste<Node *> DiGraph::getNeightbours(std::string key) {
    Liste<Node *> nodes = Liste<Node *>();
    Liste<Edge *> edges = getEdges(key);
    Edge *currentEdge;
    Node *currentNode;

    for (int i = 0; i < edges.size(); i++) {
        currentEdge = edges.getValueAt(i);
        currentNode = currentEdge->getStartNode();

        if (currentNode->getKey() != key) {
            nodes.append(currentNode);
            continue;
        }

        currentNode = currentEdge->getEndNode();

        if (currentNode->getKey() != key)
            nodes.append(currentNode);
    }

    return nodes;
}

Liste<Edge *> DiGraph::getEdges(std::string key) {
    Liste<Edge *> edgeList = Liste<Edge *>();
    int i = 0;

    while (nodes[i]) {
        if (nodes[i]->getKey() == key) {
            edgeList = nodes[i]->getEdges();
            break;
        }

        i++;
    }

    return edgeList;
}

Liste<Node *> DiGraph::getNodes() {
    Liste<Node *> nodeList = Liste<Node *>();
    int i = 0;

    while (nodes[i]) {
        nodeList.append(nodes[i]);
        i++;
    }

    return nodeList;
}

GraphVisualizer *DiGraph::getVisualizer() {
    return graphvisualizer;
}

void DiGraph::setVisualizer(GraphVisualizer *graphvis) {
    graphvisualizer = graphvis;
}

void DiGraph::saveGraphToFile(std::string path) {
    std::string dataNode = "# Alle Knoten";
    std::string dataEdge = "# Alle Kanten";
    Node *node;
    Edge *edge;

    for (int i = 0; i < getNodes().size(); i++) {
        node = getNodes()[i];
        dataNode += "\n" + node->getKey() + " " + std::to_string(node->getPositionX()) + " " +
                    std::to_string(node->getPositionY());

        for (int e = 0; e < getEdges(node->getKey()).size(); e++) {
            edge = getEdges(node->getKey())[e];
            dataEdge += "\n" + edge->getStartNode()->getKey() + " " + edge->getEndNode()->getKey() + " " +
                        std::to_string(edge->getWeight());
        }
    }

    std::ofstream fileStream;
    fileStream.open(path);
    fileStream << dataNode << "\n" << dataEdge;
    fileStream.close();
}

void DiGraph::loadGraphFromFile(std::string path) {
    std::string data = "";
    std::string line;
    std::ifstream fileStream(path);

    if (fileStream.is_open()) {
        while (getline(fileStream, line)) {
            data += line + "\n";
        }

        fileStream.close();

        StringTokenizer token(data, "\n");
        int dataBlock = 0;

        while (token.hasMoreTokens()) {
            line = token.nextToken();
            StringTokenizer token2(line, " ");
            std::string dataSet[3];

            int i = 0;

            while (token2.hasMoreTokens()) {
                std::string dataPiece = token2.nextToken();

                if (dataPiece == "#" || i >= 3) {
                    break;
                } else
                    dataSet[i] = dataPiece;

                i++;
            }

            if (dataSet[0].empty()) {
                dataBlock++;
                continue;
            }

            if (dataBlock == 1) {
                //std::cout << "Knoten\n" << "." << dataSet[0] << ". ." << dataSet[1] << ". ." << dataSet[2] << "." << std::endl;

                try {
                    int posX = std::stoi(dataSet[1]);
                    int posY = std::stoi(dataSet[2]);
                    addNode(dataSet[0], posX, posY);
                }
                catch (...) {
                    std::cerr << "\"" << dataSet[0] << " " << dataSet[1] << " " << dataSet[2] << "\" is not valid"
                              << std::endl;
                }
            } else if (dataBlock == 2) {
                //std::cout << "Kante\n" << "." << dataSet[0] << ". ." << dataSet[1] << ". ." << dataSet[2] << "." << std::endl;

                bool endNodeExists = false;
                bool startNodeExists = false;

                for (int i = 0; i < getNodes().size(); i++) {
                    Node *n = getNodes().getValueAt(i);

                    if (dataSet[0] == n->getKey())
                        startNodeExists = true;

                    if (dataSet[1] == n->getKey())
                        endNodeExists = true;
                }

                if (startNodeExists && endNodeExists) {
                    try {
                        float weight = std::stof(dataSet[2]);
                        addEdge(dataSet[0], dataSet[1], weight);
                    }
                    catch (...) {
                        std::cerr << "\"" << dataSet[0] << " " << dataSet[1] << " " << dataSet[2] << "\" is not valid"
                                  << std::endl;
                    }
                }
            }
        }
    }
}