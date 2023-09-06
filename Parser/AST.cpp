#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "AST.h"

using namespace std;

string Node::JSON() {
    return "IN PROGRESS";
}

// Node::Node(string type, string value, vector<unique_ptr<Node>> children) {
//     this->type = type;
//     this->value = value;
//     this->children = move(children);
// }

Literal::Literal() {
}

// polymorph literal class JSON
string Literal::JSON() {
    return "{\"type\":\"" + this->type + "\",\"value\":\"" + this->value + "\"}";
}

Identifier::Identifier() {
}