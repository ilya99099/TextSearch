//
// Created by user on 1/28/2025.
//
#include "../include/TextParser.h"
#include <cctype>
using namespace std;

vector<string> TextParser::tokenize(const string& text) {
    vector<string> words;
    string current;

    for (char c : text) {
        if (isalnum(static_cast<unsigned char>(c))) {
            current.push_back(tolower(static_cast<unsigned char>(c)));
        } else {
            if (!current.empty()) {
                words.push_back(current);
                current.clear();
            }
        }
    }
    if (!current.empty()) {
        words.push_back(current);
    }

    return words;
}