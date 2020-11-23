#ifndef QUEUE
#define QUEUE

#include "../../include/DataStructures/LinkedList.h"

/**
 * @brief Structure containing the first and last node of the list. Queue allows you to manage items like a queue. 
 * FIFO : First In First Out
 * 
 */
typedef struct Queue {
    Node* first;
    Node* last;
} Queue;


Queue*          initQueue                       (void);
int             pushQueue                       (Queue** f, HuffmanNode* nx_elem);
HuffmanNode*    pullQueue                       (Queue** f);
void            reverseQueue                    (Queue** q);


#endif // !QUEUE
