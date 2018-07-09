#ifndef PROJECT_ORIGINAL_SFMLGRAPHVISUALIZER_H
#define PROJECT_ORIGINAL_SFMLGRAPHVISUALIZER_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "GraphVisualizer.h"

class DiGraph;

class SFMLGraphVisualizer : public GraphVisualizer {
public:
    SFMLGraphVisualizer();
    void visualize(DiGraph &g);
    void drawNode(Node &node, sf::Color nodeColor);
    void drawEdge(Edge &edge, sf::Color color, double weight, int thickness = 1, int arrowMagnitude = 20);
    void highlightPath(Liste<Edge*> path);
private:
    sf::RenderWindow window;
    sf::Font font;
    Liste<Edge*> path;
    void Update(DiGraph &g);
    void Draw(DiGraph &g);
    sf::Vector2i mousePositionLast;
    bool movingNode;
    Node *selectedNode;
};

#endif //PROJECT_ORIGINAL_SFMLGRAPHVISUALIZER_H
