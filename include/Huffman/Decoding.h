#ifndef DECODING
#define DECODING

#include "../../include/Huffman/HuffmanTree.h"

char*            decodeFile                  (FILE *file);
HuffmanTree     buildFromDictionary         (FILE *file);
HuffmanTree     buildTreeFromCode           (HuffmanTree tree, char integer);
char*           buildString                 (FILE *file);
//Queue*           occListFromFile             (FILE *file);
unsigned int getCodeSizeMax(FILE* file);
unsigned int getSizeFile(FILE* file);
void buildFromCode(HuffmanTree tree, char letter, char* code, int index, int sizeCode);

#endif // !DECODING