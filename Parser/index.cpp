#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "lexer.h"
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Read Program
    string file = argv[1];
    fstream f(file);
    string program;
    while(!f.eof()) {
        string line;
        getline(f, line);
        program += line + "\n";
    }
    f.close();
    
    // Lexical Analysis
    Lexer lexer = Lexer(program);
    lexer.tokenify();

    // Parsing
    Parser parser;
    parser.parse(lexer.tokens);
    cout << parser.AST.size() << endl;

    // Dump JSON
    fstream out("out.json", ios::out);
    out << "[";
    for (int i = 0; i < parser.AST.size(); i++) {
        out << parser.AST[i]->JSON();
        if (i != parser.AST.size() - 1) {
            out << ",";
        }
    }
    out << "]";

    return 0;
}