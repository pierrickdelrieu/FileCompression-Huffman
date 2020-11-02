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