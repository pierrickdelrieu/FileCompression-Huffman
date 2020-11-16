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
void printDictionaryOnFile(HuffmanNode* huffman, char* code, int sizecode, FILE* file);
long int countLineFile(FILE* file);
void printToFile(int size, char* s, char c, FILE* file);
void createDictionary(HuffmanTree huffman);
void printDictionaryOnFile(HuffmanNode* huffman, char* code, int sizecode, FILE* file);
DicoNode* createDicoNode(int** returnline);
void printString(char* c, int size);
void printDicoNode(DicoNode* dico, int lines);
DicoNode* readDictionary();

#endif // !DICTIONARY