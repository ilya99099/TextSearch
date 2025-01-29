//
// Created by user on 1/29/2025.
//

#ifndef QUERYENGINE_H
#define QUERYENGINE_H

#include "InvertedIndex.h"
#include <vector>
#include <string>
using namespace std;

class QueryEngine {
    public:
        QueryEngine(const InvertedIndex& idx);

        vector<int> searchAll(const vector<string>& words) const;

    private:
        const InvertedIndex& m_index;
};

#endif
