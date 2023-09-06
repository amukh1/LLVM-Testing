#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "lexer.h"

using namespace std;

vector<vector<string>> regtok = {
    {"COMMENT", "^\\/\\/.*\\/"},
    {"MCOMMENT", "^\\/\\*[\\s\\S]*?\\*\\n"}, // 24
    {"NULL", "^\\s+"}, // 0
    {"SEMI", "^;"},
    {"NUMBER", "^[\\d\\.]+"}, // 2
    {"WORD", "^[a-zA-Z_][_a-zA-Z\\d\\.]*"},
    {"STRING", "^\"[^\"]*\"|^'[^']*'"}, // 4
    {"O-PAREN", "^\\("},
    {"C-PAREN", "^\\)"}, // 6
    {"O-BRACE", "^\\{"},
    {"C-BRACE", "^\\}"}, // 8
    {"O-BRACK", "^\\["},
    {"C-BRACK", "^\\]"}, // 10
    {"EXPI", "^\\!"},
    {"COLON", "^:"}, // 12
    {"GRT", "^>"},
    {"LST", "^<"}, // 14
    {"DECLARATION", "^="},
    {"EQUALITY", "^=="}, // 16
    {"COMMA", "^,"},
    {"OPP", "^\\->"}, // 18
    {"OPP", "^\\+"}, // 18
    {"OPP", "^-"},
    {"STAR", "^\\*"}, // 20
    {"OPP", "^\\/"},
    {"OPP", "^\\.\\."}, // 22
    {"AMP", "^&"}, // 22
};


Lexer::Lexer(string program) {
    this->program = program;
}

void Lexer::tokenify() {
    string text = this->program;
    while(text.length() > 0) {
        for(vector<string> expression : regtok) {
            regex reg = regex(expression[1]);
            smatch match;
            if(regex_search(text, match, reg)) {
                string token = match.str();
                if(expression[0] == "NULL" || expression[0] == "COMMENT" || expression[0] == "MCOMMENT") {
                    text = regex_replace(text, reg, "");
                } else if(expression[0] != "STRING"){
                    text = regex_replace(text, reg, "");
                    this->tokens.push_back({expression[0], token});
                } else {
                    text = regex_replace(text, reg, "");
                    this->tokens.push_back({expression[0], token.substr(1, token.length() - 2)});
                }
                break;
            }
        }
    }
}