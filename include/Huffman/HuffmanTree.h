#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "../../include/DataStructures/Queue.h"

typedef HuffmanNode* HuffmanTree;

LinkedList occChar  (void);

HuffmanTree createHuffmanTree(Queue* occQueue);

Queue*          createSortOccQueue      (void);




#endif // !HUFFMAN_TREE