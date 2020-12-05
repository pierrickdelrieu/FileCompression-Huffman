/**
 * @file Decoding.h
 * @author Benjamin Lesieux
 * @brief Decoding functions
 * @version 0.1
 * @date 26-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */


#ifndef DECODING
#define DECODING

#include "../../include/Huffman/HuffmanTree.h"

/**
 * @brief decodes the encoded file into HuffmanDecompression.txt
 * @details from the dictionary file, the function will create an huffmantree that will be use to decode the encoded file
 * */
void decodeFile();

/**
 * @brief builds an huffman tree from the dictionary file
 * @param file is the file in which the dictionary is in
 * */
HuffmanTree buildFromDictionary(FILE *file);


HuffmanTree buildTreeFromCode(HuffmanTree tree, char integer);

/**
 * @brief search and returns the size of the biggest code
 * @param file is the file where the dictionary is
 * @return an unsigned integer that is equal to the size of the biggest code
 * */
unsigned int getCodeSizeMax(FILE *file);

/**
 * @brief add a node to tree at the place showed by the code
 * @param tree the parent of the huffman tree
 * @param letter the current letter we want to place in the tree
 * @param code the code of the current letter
 * @param index the current index of the code of the letter we are placing
 * @param sizeCode the size of the code
 * */
void buildFromCode(HuffmanTree tree, char letter, char *code, int index, int sizeCode);

#endif // !DECODING