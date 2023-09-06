#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "parser.h"
#include "AST.h"

using namespace std;

void Parser::parse(vector<vector<string>> tokens) { // this->AST.push_back((unique_ptr<Node>) make_unique<Literal>(move(CHILD_NODE)));
    for (int i = 0; i < tokens.size(); i++) {
        vector<string> token = tokens[i];
        if (token[0] == "STRING" || token[0] == "NUMBER") {
            Literal literal = Literal();
            literal.type = token[0];
            literal.value = token[1];

            this->AST.push_back((unique_ptr<Node>) make_unique<Literal>(move(literal)));
        }
    }
    return;
}
