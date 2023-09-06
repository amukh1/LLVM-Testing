#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lexer {
    public:
        string program;
        vector<vector<string>> tokens;
        Lexer(string program);
        void tokenify();
};