/**
 * @file HuffmanTree.h
 * @author Pierrick Delrieu - Benjamins Lesieux - Harold Molter
 * @brief
 * @version 0.1
 * @date 08-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "../../include/DataStructures/Queue.h"

typedef HuffmanNode* HuffmanTree;

/**
* @brief function to determine the number of occurence of a character in a file
*
* @return list of char with their respective occurrence
*/
LinkedList      occChar                 (void);

/**
 * @brief Create a Huffman Tree
 * @param occQueue
 * @return HuffmanTree
 */
HuffmanTree     createHuffmanTree       (Queue* occQueue);

/**
 * @brief Create a Sort Queue From Occ List object
 *
 * @param list
 * @return Queue*
 */
Queue*          createSortOccQueue      (void);

/**
 * @brief Calculate HuffmanTree depth
 * @param HuffmanTree
 * @return int
 */
int             depthOfHuffmanTree      (HuffmanTree tree);

/**
 * @brief Memory release
 *
 * @param tree Tree has to free memory because dynamically allocated
 */
void            freeHuffmanTree         (HuffmanTree tree);


#endif // !HUFFMAN_TREE