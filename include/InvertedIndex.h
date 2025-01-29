//
// Created by user on 1/28/2025.
//

#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class InvertedIndex {
    public:
        int addFile(const string& filePath);

        void addWordOccurrence(const string& word, int fileId);

        int getFileCount() const;

        string getFilePath(int fileId) const;

        map<int,int>getOccurrences(const string& word) const;
    private:
        vector<string> m_files;
        unordered_map<string,map<int,int>> m_index;
};

#endif
