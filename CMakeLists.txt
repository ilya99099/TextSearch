cmake_minimum_required(VERSION 3.15)
project(TextSearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextSearch
        main.cpp
        src/FileScanner.cpp
        include/FileScanner.h
        include/FileScanner.h
        src/FileScanner.cpp
        include/TextParser.h
        src/TextParser.cpp
        include/InvertedIndex.h
        src/InvertedIndex.cpp
        include/QueryEngine.h
        src/QueryEngine.cpp
)

