#ifndef OUTPUT_NODE_H
#define OUTPUT_NODE_H

#include <iostream>
#include "../node/node.h"
#include "../core/evaluation.h"

// Rather than doing a SetNode method, we are using the contructor
// meaning that the value that passes into the Output node needs to
// be the equivelent of the following Python code:
// self.node = node._parameters["image"].binding

class OutputNode 
{
    public:
        Node* node = nullptr;

        OutputNode(Node *output_node) 
        {
            node = output_node;
        }

        ~OutputNode() 
        {
            delete node;
        }

        int RenderImage();

};

#endif // OUTPUT_NODE_H