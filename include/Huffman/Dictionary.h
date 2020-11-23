#ifndef DICTIONARY
#define DICTIONARY

#include "HuffmanTree.h"
#include "../FileManagment.h"


typedef struct DicoNode {
	char* code; 
	int letter;
	struct DicoNode* left;
	struct DicoNode* right;
} DicoNode;

DicoNode* createDicoNode(int letter, char* code);

typedef DicoNode* DicoTree; // AVL


extern int 	depthOfDicoTree		(DicoTree tree);

extern int 	getBalanceFactor	(DicoTree tree);

extern void 	leftRotation		(DicoTree* tree);

extern void 	rightRotation		(DicoTree* tree);

extern void 	balanceTree			(DicoTree* tree);

extern void 	addNodeAVL			(DicoTree* tree, int letter, char* code);



extern DicoTree	createDicoTree			(HuffmanTree tree);

extern void		initDicoTree			(DicoTree* avl, HuffmanTree tree, char *code, int sizecode) ;

extern void		initDictionaryPrinting	(DicoTree dicoTree);

extern void		printDictionaryFile		(DicoTree dicoTree, FILE* file);


#endif // !DICTIONARY