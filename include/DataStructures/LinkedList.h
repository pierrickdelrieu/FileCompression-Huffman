#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node {
    int letter;
    int occ;
    struct Node* right;
    struct Node* left;
} Node;

typedef Node* LinkedList;

Node*      createNode     (int letter, int occ);

void       addNode            (LinkedList* list, Node* node);

void       removeNode         (LinkedList* list, int letter);

Node*      find           (LinkedList list, int letter);

int        getSize        (LinkedList list);

void       printList      (LinkedList list);

#endif // !LINKED_LIST
