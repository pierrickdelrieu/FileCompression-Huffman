/**
 * @file Menu.h
 * @author Pierrick Delrieu
 * @brief Function containing all the functionalities of the software and their display
 * @version 0.1
 * @date 17-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef MENU
#define MENU

/**
 * @brief Display and user choice of software features
 *
 * @return int User choice
 */
int     displayMenu     (void);

/**
 * @brief Functionality: adding a text in the "FileToCompress.txt" file
 *
 */
void    addText         (void);

/**
 * @brief Functionality: compression of the "FileToCompress.txt" file with data calculation
 *
 */
void    compressFile    (void);

/**
 * @brief Functionality: decompression of the file "FileToCompress.txt" with calculation of the decompression time
 *
 */
void    decompressFile  (void);


#endif // !MENU