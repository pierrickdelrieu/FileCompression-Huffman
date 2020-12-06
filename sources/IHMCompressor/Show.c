#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/IHMCompressor/Show.h"




void displayErrorMessageOpenFile(void) {
    printf("FILE OPENING ERROR\n");
    exit(EXIT_FAILURE); // Forced program exit with failure
}



void cleanTerminal(void) {
    system(strcmp(OPERATING_SYSTEM, "win") == 0 ? "cls" : "clear");
}



void displayErrorMemoryAllocation(void) {
    printf("MEMORY ALLOCATION ERROR\n");
    exit(EXIT_FAILURE); // Forced program exit with failure
}



int stopExe(int secTime) {
    struct timespec tim, tim2;
    tim.tv_sec = 1;
    tim.tv_nsec = secTime*100000000; // Nanosecond conversion

    // Nano sleep system call failed
    if(nanosleep(&tim , &tim2) < 0 ) {
       return -1;
    }

    // Nano sleep successfull
    return 0;
}