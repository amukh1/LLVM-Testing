#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class Node {
   public:
        string type;
        string value;
        vector<unique_ptr<Node>> children;
        Node() = default;
        virtual string JSON();
        virtual ~Node() = default;
        Node(Node &&) = default;
};

class Literal : public Node {
        public:
        Literal(); // string type, string value
        // ~Literal() = default;
        string JSON();
};

class Identifier : public Node {
        public:
        Identifier(); // string type, string value
        // ~Identifier() = default;
};