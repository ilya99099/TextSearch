//
// Created by user on 1/28/2025.
//

#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <vector>
#include <string>

class FileScanner {
    public:
        FileScanner(const std::string& rootPath);
        std::vector<std::string> getFileList();
    private:
        std::string m_rootPath;
};

#endif
