#include <stdio.h>
#include <stdlib.h>
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