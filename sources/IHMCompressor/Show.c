#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"



void displayErrorMessageOpenFile() {
    printf("FILE OPENING ERROR\n");
    exit(EXIT_FAILURE);
}


void cleanTerminal() {
    system(strcmp(OPERATING_SYSTEM, "win") == 0 ? "cls" : "clear");
}