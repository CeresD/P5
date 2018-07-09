#ifndef PROJECT_ORIGINAL_GRAPHVISUALIZER_H
#define PROJECT_ORIGINAL_GRAPHVISUALIZER_H

class DiGraph;

#include "DiGraph.h"

class GraphVisualizer {
public:
    void render(DiGraph g);
    void show();
    void highlightPath(Liste<Edge*> path);
private:
};


#endif //PROJECT_ORIGINAL_GRAPHVISUALIZER_H
