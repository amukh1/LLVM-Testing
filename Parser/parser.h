#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "AST.h"

using namespace std;

class Parser {
    public:
    vector<unique_ptr<Node>> AST;
    void parse(vector<vector<string>> tokens);
};