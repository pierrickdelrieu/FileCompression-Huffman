#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

typedef struct Node {
    int letter;
    int occ;
    struct Node *next;
} Node;

typedef *Node LinkedList;









typedef struct Leaf {
    int letter;
    struct Leaf left;
    struct Leaf right;
} Leaf;

typedef *Lead HuffmanTree;

HuffmanTree           createHuffmanTreeFromOccList  (LinkedList occList);
static HuffmanTree    createLeaf                    (int letter);

#endif // !HUFFMAN_TREE