#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "../../include/DataStructures/Queue.h"

LinkedList occChar  (void);
Queue* createSortOccQueue(void);





int compareHuffmanNode(HuffmanNode* node1, HuffmanNode* node2);

typedef HuffmanNode* HuffmanTree;



#endif // !HUFFMAN_TREE