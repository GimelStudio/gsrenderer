#include <iostream>
#include <string>
#include "parameter.h"
#include "node.h"

struct Parameter {
    std::string name;
    std::string idname;
    Node binding;
};