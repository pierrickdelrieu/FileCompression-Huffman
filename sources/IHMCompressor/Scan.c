/**
 * @file Scan.c
 * @author Pierrick Delrieu
 * @brief Input functions
 * @version 0.1
 * @date 17-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Scan.h"


/**
 * @brief Entering an integer with the erasure of the input and output buffers
 * 
 * @param integer Memory address in which the integer must be entered
 */
void scanInteger(int* integer) {
    fflush(stdin);
    scanf("%d", integer);
    fflush(stdout);
}


/**
 * @brief Entering a character with the erasure of the input and output buffers
 * 
 * @param string Memory address in which the character must be entered
 */
void scanChara(char* chara) {
    fflush(stdin);
    scanf("%c",chara);
    fflush(stdout);
}


/**
 * @brief Entering a character string with deletion of input and output buffers
 * 
 * @param strings Memory address of the character string allocated and to be written
 * @param nbChar Maximum number of characters the string must contain
 */
void scanString(char** string, int nbChara) {
    fflush(stdin);

    *string = (char*) malloc(nbChara * sizeof(char));
    fgets(*string,nbChara,stdin);

    char *position_cara_entree = NULL;
    position_cara_entree = strchr(*string, '\n'); // On recherche le caractère 'entrée' de validation de saisie
    if (position_cara_entree != NULL) {
        *position_cara_entree = '\0'; // On remplace ce caractère par \0
    }

    fflush(stdout);
}