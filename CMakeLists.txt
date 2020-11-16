
cmake_minimum_required(VERSION 3.15)
project(FileCompression-Huffman C)

set(CMAKE_C_STANDARD 99)
set(sources
        tests/tests.c
        sources/FileManagment.c
        sources/DataStructures/LinkedList.c
        sources/DataStructures/Queue.c
        sources/Huffman/Decoding.c
        sources/Huffman/Dictionary.c
        sources/Huffman/Encoding.c
        sources/Huffman/HuffmanTree.c
        sources/IHMCompressor/Menu.c
        sources/IHMCompressor/Scan.c
        sources/IHMCompressor/Show.c
        sources/main.c
        )

set(headers
        tests/tests.h
        include/FileManagment.h
        include/DataStructures/LinkedList.h
        include/DataStructures/Queue.h
        include/Huffman/Decoding.h
        include/Huffman/Dictionary.h
        include/Huffman/Encoding.h
        include/Huffman/HuffmanTree.h
        include/IHMCompressor/Menu.h
        include/IHMCompressor/Scan.h
        include/IHMCompressor/Show.h
        )

add_executable(FileCompression-Huffman ${sources} ${headers})