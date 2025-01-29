//
// Created by user on 1/29/2025.
//
#include "../include/QueryEngine.h"

QueryEngine::QueryEngine(const InvertedIndex &idx)
    : m_index(idx)
{}

vector<int> QueryEngine::searchAll(const vector<string> &words) const{
    vector<int> result;

    if(words.empty()) {
        return result;
    }

    auto firstOccurrences = m_index.getOccurrences(words[0]);
    for (auto & [fid, freq] : firstOccurrences) {
        result.push_back(fid);
    }

    for (size_t i = 1; i < words.size(); ++i) {
        auto occ = m_index.getOccurrences(words[i]);
        vector <int> nextResult;
        for (int fid : result) {
            if (occ.find(fid) != occ.end()) {
                nextResult.push_back(fid);
            }
        }
        result = nextResult;
        if (result.empty()) {
            break;
        }
    }
    return result;
}
