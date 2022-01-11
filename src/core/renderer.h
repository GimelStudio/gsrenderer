#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include <vector>
#include "../node/node.h"

class Renderer {

    int Render(std::vector<Node> nodes);

    int RenderNodeGraph(Node node);

    Node GetOutputNode(std::vector<Node> nodes);
    
};

#endif // RENDERER_H