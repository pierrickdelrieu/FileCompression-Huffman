#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "../../include/DataStructures/Queue.h"

typedef HuffmanNode* HuffmanTree;

extern LinkedList      occChar                 (void);

extern HuffmanTree     createHuffmanTree       (Queue* occQueue);

extern Queue*          createSortOccQueue      (void);

extern int             depthOfHuffmanTree      (HuffmanTree tree);


#endif // !HUFFMAN_TREE