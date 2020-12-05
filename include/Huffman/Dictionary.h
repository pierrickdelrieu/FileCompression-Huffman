/**
 * @file Dictionary.h
 * @author Pierrick Delrieu - Faustin Dewas
 * @brief Creation of a dictionary with each letter and its binary code compressed
 * @version 0.1
 * @date 23-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef DICTIONARY
#define DICTIONARY

#include "HuffmanTree.h"
#include "../FileManagment.h"

/**
 * @brief Node of an AVL
 * 
 */
typedef struct DicoNode {
	char* code; 
	int letter;
	struct DicoNode* left;
	struct DicoNode* right;
} DicoNode;


/**
 * @brief Create a DicoNode
 *
 * @param letter Node field
 * @param code Node field
 * @return DicoNode* Address of the created node
 */
DicoNode* createDicoNode(int letter, char* code);

typedef DicoNode* DicoTree; // AVL

/**
 * @brief Depth of DicoTree
 *
 * @param tree Tree whose depth is to be found
 * @return int Depth of Tree
 */
int 	depthOfDicoTree		(DicoTree tree);

/**
 * @brief Get the Balance Factor of DicoNode
 *
 * @param tree
 * @return int
 */
int 	getBalanceFactor	(DicoTree tree);

/**
 * @brief LeftRotation of Node
 *
 * @param tree Node at the origin of the rotation
 */
void 	leftRotation		(DicoTree* tree);


/**
 * @brief RightRotation of Node
 *
 * @param tree Node at the origin of the rotation
 */
void 	rightRotation		(DicoTree* tree);

/**
 * @brief Tree balance
 *
 * @param tree Tree Balanced
 */
void 	balanceTree			(DicoTree* tree);

/**
 * @brief Adding a node to a balanced binary search tree
 * @details Binary trees sort by code size
 *
 * @param tree
 * @param letter
 * @param code
 */
void 	addNodeAVL			(DicoTree* tree, int letter, char* code);


/**
 * @brief Memory release
 *
 * @param tree Tree has to free memory because dynamically allocated
 */
void 	freeDicoTree		(DicoTree tree);


/**
 * @brief Create a Dico Tree object
 *
 * @param tree Huffman tree to retrieve the codes
 * @return DicoTree Balanced binary search tree containing these letters with its code
 */
DicoTree	createDicoTree			(HuffmanTree tree);

/**
 * @brief Recursive function which initializes the tree containing each letter and its code
 *
 * @param avl Avl to create
 * @param tree Huffman tree from which the AVL is created
 * @param code Initialized when calling the function
 * @param sizecode Initialized when calling the function at 0
 */
void		initDicoTree			(DicoTree* avl, HuffmanTree tree, char *code, int sizecode) ;

/**
 * @brief Function that opens and calls the recursive function to create the dictionary file
 *
 * @param dicoTree AVL containing letters and codes
 */
void		initDictionaryPrinting	(DicoTree dicoTree);

/**
 * @brief Recursive function which writes the code of each letter in the text file
 *
 * @param dicoTree AVL containing letters and codes
 * @param file File to write to (previously opened)
 */
void		printDictionaryFile		(DicoTree dicoTree, FILE* file);


#endif // !DICTIONARY