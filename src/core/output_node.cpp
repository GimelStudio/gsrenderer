#include <iostream>
#include "../core/evaluation.h"
#include "output_node.h"


int OutputNode::RenderImage() 
{
    if (node != nullptr) 
    {
        Evaluation eval(node);

        int image; // integer for now
        //image = eval.node.EvaluateNode(eval);
        return image;
    } else {
        int image {10000}; // Default
        return image;
    }
}
