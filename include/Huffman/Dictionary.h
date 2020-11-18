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


char* addCharToNewString(char* c, char s, int size);
int countLineFile(FILE* file);
void printDictionaryOnFile(HuffmanNode* huffman, char* code, int sizecode, FILE* file);
DicoNode* createDicoNode(int** returnline);
void printString(char* c, int size);
void printDicoNode(DicoNode* dico, int lines);
void readDictionary(FILE* filedico, DicoNode* dico);

#endif // !DICTIONARY