#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

typedef struct HuffmanNode {
    int letter;
    int occ;
    struct HuffmanNode* right;
    struct HuffmanNode* left;
} HuffmanNode;

///@brief Defines the pointer of a doubly linked list
typedef Node* LinkedList;

typedef struct Node {
    HuffmanNode* data;
    struct Node* next;
} Node;

#endif // !HUFFMAN_TREE