#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef DICTIONARY
#define DICTIONARY

typedef struct DicoNode {
	char* code;	//Binary
	char letter;
	int sizecode;
}DicoNode;


void addCharToString(char* s, char c, int size);
void printDictionaryOnFile(Leaf* huffman);
void printToFile(int size, char* s, char c, FILE* file);

DicoNode* readDictionary();

#endif // !DICTIONARY