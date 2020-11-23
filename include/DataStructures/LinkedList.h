#ifndef LINKED_LIST
#define LINKED_LIST


typedef struct HuffmanNode {
    int letter;
    int occ;
    struct HuffmanNode* right;
    struct HuffmanNode* left;
} HuffmanNode;


typedef struct Node {
    HuffmanNode* data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

extern HuffmanNode*      createHuffmanNode     (int letter, int occ);

extern Node*             createNode            (HuffmanNode* data);

extern void              addNode               (LinkedList* list, Node* node);

extern void              removeNode            (LinkedList* list, HuffmanNode* huffmanNode);

extern Node*             find                  (LinkedList list, int letter);

extern int               getSize               (LinkedList list);

extern Node*             findMinOccLetter      (LinkedList list);


#endif // !LINKED_LIST
