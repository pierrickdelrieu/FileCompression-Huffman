/**
 * @file HuffmanTree.c
 * @author Harold Molter
 * @brief 
 * @version 0.1
 * @date 08-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/HuffmanTree.h"
#include "../../include/IHMCompressor/Show.h"



/**
* @brief function to determine the number of occurence of a character in a file
* 
* @return list of char with their respective occurrence
*/
LinkedList occChar(void) {

	FILE* file = NULL;
	file = fopen("TextFiles/FileToCompress.txt", "r");	// access path to verify...? 

	// checking if file is open 
	if (file != NULL) {
		LinkedList list = NULL;								// list to return
		LinkedList temp = NULL;								// copy of list, to go through it
		int char_f = fgetc(file);							// char being read in file

		list = createNode(createHuffmanNode(char_f, 1));

		// go through whole file
		while (char_f != EOF) {
			char_f = fgetc(file);
			temp = find(list, char_f);						// check if char already in list

			// letter is in list
			if (temp != NULL) {
				temp->data->occ = temp->data->occ + 1;
			}
			// letter not in list
			else {
				LinkedList newE = createNode(createHuffmanNode(char_f, 1));
				addNode(&list, newE);
			}
		}
		fclose(file);

		// Remove char(EOF)
		HuffmanNode* eof = find(list, EOF)->data;
		removeNode(&list, eof);


		return list;
	}
	else {
		displayErrorMessageOpenFile();
	}

	return NULL;
}

/**
 * @brief Compare huffman nodes according to their occurrence
 * 
 * @param node1 Node to compare
 * @param node2 Node to compare
 * @return int 1 if occ(node1) > occ(node2)
 *             -1 if occ(node1) < occ(node2)
 *             0 if occ(node1) = occ(node2)
 */
int compareHuffmanNode(HuffmanNode* node1, HuffmanNode* node2) {
	if((node1 == NULL) && (node2 != NULL)) {
		return -1;
	}
	else if((node1 != NULL) && (node2 == NULL)) {
		return 1;
	}
    else if(node1->occ > node2->occ) {
        return 1;
    } 
    else if(node1->occ < node2->occ) {
        return -1;
    }
    else {
        return 0;
    }
}


// HuffmanNode* returnSortNode(Queue* occQueue; Queue* nodeQueue)



// HuffmanTree createHuffmanTree() {
// 	Queue* occQueue = initQueue;
// 	Queue* nodeQueue = initQueue;

// 	occQueue = createSortOccQueue();

// 	while((getSize(occQueue->start) != 0) || (getSize(nodeQueue->start) > 1)) {
		
// 	}

// }