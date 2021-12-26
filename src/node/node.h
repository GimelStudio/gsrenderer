#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>


class Node { 
  public:  
    int id {0};
    bool isOutput {false};
    std::string idname;

    Node(std::string name, int id) {
      idname = name;
      id = id;
    }

    void setAsOutput(bool output) { 
      isOutput = output;
    }
};

#endif // NODE_H