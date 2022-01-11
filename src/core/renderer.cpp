#include <iostream>
#include <string>
#include <vector>
#include "../node/node.h"
#include "../core/output_node.h"
#include "renderer.h"

// For now just do a test with integers and so the datatypes relect that
int Renderer::Render(std::vector<Node> nodes) {
    Node output_node = Renderer::GetOutputNode(nodes);
    Renderer::RenderNodeGraph(output_node);
    return 0;
}

int Renderer::RenderNodeGraph(Node node) { // int for now
    OutputNode output_node(&node);
    return output_node.RenderImage();
}

Node Renderer::GetOutputNode(std::vector<Node> nodes) {
    // Loop through nodes to get the output node

    Node output_node("test", 54); // for now
    std::vector<Node>::iterator iter;

    // for (iter = nodes.begin(); iter != nodes.end(); ++iter) {
    //     std::cout << *iter << "  ";
    // }

    // for(int i; i < nodes.size(); i++) {
    //     if (nodes[i].isOutput() == true) {
    //         output_node = nodes[i];
    //     }
    // }
    
    return output_node;
}
