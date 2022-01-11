#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include "Parameter.h"
#include "Property.h"
//#include "../core/evaluation.h"


class Node 
{ 
    public:  
        int id = 0;
        bool is_output = false;
        std::string idname = "";
        std::vector<Property> properties;
        std::vector<Parameter> parameters;

        Node(std::string name, int id) 
        {
            idname = name;
            id = id;
        }

        void SetAsOutput(bool output);

        //int EvaluateNode(Evaluation *eval);
};

#endif // NODE_H