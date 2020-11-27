#ifndef DECODING
#define DECODING

#include "../../include/Huffman/HuffmanTree.h"

void decodeFile();

HuffmanTree buildFromDictionary(FILE *file);

HuffmanTree buildTreeFromCode(HuffmanTree tree, char integer);

unsigned int getCodeSizeMax(FILE *file);

void buildFromCode(HuffmanTree tree, char letter, char *code, int index, int sizeCode);

#endif // !DECODING