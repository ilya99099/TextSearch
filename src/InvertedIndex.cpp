//
// Created by user on 1/28/2025.
//
#include "../include/InvertedIndex.h"

int InvertedIndex::addFile(const string& filePath) {
    m_files.push_back(filePath);
    return (int)m_files.size() - 1;
}

void InvertedIndex::addWordOccurrence(const string& word, int fileId) {
    m_index[word][fileId]++;
}

int InvertedIndex::getFileCount() const {
    return (int)m_files.size();
}

string InvertedIndex::getFilePath(int fileId) const {
    if (fileId < 0 || fileId>=(int)m_files.size()) {
        return "";
    }
    return m_files[fileId];
}

map<int, int> InvertedIndex::getOccurrences(const string& word) const {
    auto it = m_index.find(word);
    if (it != m_index.end()) {
        return it -> second;
    }
    return {};
}




