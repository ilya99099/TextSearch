//
// Created by user on 1/28/2025.
//
#include "../include/FileScanner.h"
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

FileScanner::FileScanner(const string& rootPath)
    : m_rootPath(rootPath)
{}

std::vector<std::string> FileScanner::getFileList() {
    vector<string> filesPaths;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(m_rootPath)) {
            if (entry.is_regular_file()) {
                filesPaths.push_back(entry.path().string());
            }
        }
    } catch (const exception& e) {
        cerr << "Error scanning directory: " << e.what() << endl;
    }
    return filesPaths;
}
