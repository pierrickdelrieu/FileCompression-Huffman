#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Scan.h"


void scanInteger(int* integer) {
    fflush(stdin);
    scanf("%d", integer);
    fflush(stdout);
}

void scanString(char* string) {
    fflush(stdin);
    scanf("%c",string);
    fflush(stdout);
}

void scanStrings(char** strings) {
    fflush(stdin);

    *strings = (char*) malloc(300 * sizeof(char));
    fgets(*strings,300,stdin);

    char *position_cara_entree = NULL;
    position_cara_entree = strchr(*strings, '\n'); // On recherche le caractère 'entrée' de validation de saisie
    if (position_cara_entree != NULL) {
        *position_cara_entree = '\0'; // On remplace ce caractère par \0
    }

    fflush(stdout);
}