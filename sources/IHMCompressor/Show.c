/**
 * @file Show.c
 * @author Pierrick Delrieu
 * @brief Human Machine Interface: display
 * @version 0.1
 * @date 01-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/IHMCompressor/Show.h"



/**
 * @brief Display of an error message and forced exit from the program when there is a problem opening a file
 */
void displayErrorMessageOpenFile(void) {
    printf("FILE OPENING ERROR\n");
    exit(EXIT_FAILURE); // Forced program exit with failure
}


/**
 * @brief Cleaning of terminal elements for linux, windows and mac operating systems
 */
void cleanTerminal(void) {
    system(strcmp(OPERATING_SYSTEM, "win") == 0 ? "cls" : "clear");
}


/**
 * @brief Display of an error message and forced exit from the program when there is a memory allocation problem
 */
void displayErrorMemoryAllocation(void) {
    printf("MEMORY ALLOCATION ERROR\n");
    exit(EXIT_FAILURE); // Forced program exit with failure
}


/**
 * @brief Pauses program execution for n seconds
 * 
 * @param secTime Execution pause time
 * @return int 1 if the suspension of the execution was successful and 0 otherwise
 */
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