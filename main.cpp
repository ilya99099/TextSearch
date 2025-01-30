#include <iostream>
#include <fstream>
#include <string>
#include "include/FileScanner.h"
#include "include/TextParser.h"
#include "include/InvertedIndex.h"
#include "include/QueryEngine.h"
using namespace std;

int main() {
    string folderPath = "C:/Test";

    InvertedIndex index;

    {
        FileScanner scanner(folderPath);
        auto files = scanner.getFileList();

        std::cout << "=== Indexation: " << folderPath << " ===" << endl;
        std::cout << "Files found: " << files.size() << endl;
        for (auto &filePath : files) {
            cout << " - " << filePath << endl; // Printing of each indexed file

            // Adding of file to the index and getting an ID of each file
            int fileId = index.addFile(filePath);

            // Reading of files
            ifstream fin(filePath);
            if (fin.is_open()) {
                string content((istreambuf_iterator<char>(fin)),
                                    (istreambuf_iterator<char>()));
                fin.close();

                // Tokenization
                auto words = TextParser::tokenize(content);

                // Writing all words to the index
                for (auto &w : words) {
                    index.addWordOccurrence(w, fileId);
                }
            }
        }

        cout << "\nNumber of indexed files: "
                  << index.getFileCount() << endl;
    }

    // Creating of QueryEngine based on given index
    QueryEngine qe(index);

    // Asking what should we search from user and printing of the result of exit from while *
    cout << "\n=== Words search ===" << endl;
    cout << "Enter 1 or more words for search or exit:\n";

    while (true) {
        string line;
        cout << "\nSearch: ";
        if (!getline(std::cin, line)) {
            // if input was interrupted, end our program
            break;
        }

        // if "exit" was entered -> ending the program
        if (line == "exit") {
            cout << "Program ending.\n";
            break;
        }

        // tokenization
        auto queryWords = TextParser::tokenize(line);

        // search for all words from the input
        auto found = qe.searchAll(queryWords);

        // printing the results
        cout << "Match found " << found.size() << " files:\n";
        for (int fid : found) {
            cout << " - " << index.getFilePath(fid) << endl;
        }
    }

    return 0;
}
