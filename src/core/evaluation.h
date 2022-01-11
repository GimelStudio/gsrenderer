#ifndef EVALUATION_H
#define EVALUATION_H

#include <iostream>
#include <string>
#include "../node/node.h"


class Evaluation // AKA: EvalInfo
{ 
    public:
        Node* inode; 

        Evaluation(Node *eval_node) 
        {
            inode = eval_node;
        }

        ~Evaluation() 
        {
            delete inode;
        }

        int EvaluateParameter(std::string name);

        int EvaluateProperty(std::string name);
};

#endif // EVALUATION_H