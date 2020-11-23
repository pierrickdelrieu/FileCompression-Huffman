#ifndef QUEUE
#define QUEUE

#include "../../include/DataStructures/LinkedList.h"


typedef struct Queue {
    Node* first;
    Node* last;
} Queue;


extern Queue*          initQueue       (void);

extern int             pushQueue       (Queue** f, HuffmanNode* nx_elem);

extern HuffmanNode*    pullQueue       (Queue** f);


#endif // !QUEUE
