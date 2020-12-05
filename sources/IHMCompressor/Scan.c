

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Scan.h"



void scanInteger(int* integer) {
    fflush(stdin);
    scanf("%d", integer);
    fflush(stdout);
}



void scanChara(char* chara) {
    fflush(stdin);
    scanf("%c",chara);
    fflush(stdout);
}



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