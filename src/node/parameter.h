#ifndef PARAMETER_H
#define PARAMETER_H

#include <iostream>
#include <string>


class Parameter {
    public:
        int id {0};
        int binding;
        std::string idname;

    Parameter(std::string name, int id) {
        idname = name;
        id = id;
    }
};

#endif // PARAMETER_H