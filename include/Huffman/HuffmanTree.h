#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include "../../include/DataStructures/Queue.h"

typedef HuffmanNode* HuffmanTree;

LinkedList occChar  (void);

Queue* createSortOccQueue(void);

int compareHuffmanNode(HuffmanNode* node1, HuffmanNode* node2);

HuffmanNode* getMin(Queue* occQueue, Queue* nodeQueue);

HuffmanTree createHuffmanTree(Queue* occQueue);





#endif // !HUFFMAN_TREE