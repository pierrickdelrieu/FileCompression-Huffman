/**
 * @file Show.h
 * @author Pierrick Delrieu
 * @brief Human Machine Interface: display
 * @version 0.1
 * @date 01-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef SHOW
#define SHOW


/**
 * @brief Display of an error message and forced exit from the program when there is a problem opening a file
 */
void displayErrorMessageOpenFile    (void);

/**
 * @brief Cleaning of terminal elements for linux, windows and mac operating systems
 */
void cleanTerminal(void);

/**
 * @brief Display of an error message and forced exit from the program when there is a memory allocation problem
 */
void displayErrorMemoryAllocation   (void);

/**
 * @brief Pauses program execution for n seconds
 *
 * @param secTime Execution pause time
 * @return int 1 if the suspension of the execution was successful and 0 otherwise
 */
int  stopExe                        (int secTime);


//...................OPERATING SYSTEM....................
#ifdef _WIN32
#define OPERATING_SYSTEM "win" //windows
#elif __linux__
#define OPERATING_SYSTEM "linux"
#elif __APPLE__
#define OPERATING_SYSTEM "mac"
#else
#define OPERATING_SYSTEM "unk" //systéme inconnu
#endif



#endif // !SHOW
