/**
 * @file Scan.h
 * @author Pierrick Delrieu
 * @brief Input functions
 * @version 0.1
 * @date 17-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef SCAN
#define SCAN
/**
 * @brief Entering an integer with the erasure of the input and output buffers
 *
 * @param integer Memory address in which the integer must be entered
 */
void scanInteger    (int* integer);

/**
 * @brief Entering a character with the erasure of the input and output buffers
 *
 * @param string Memory address in which the character must be entered
 */
void scanChara      (char* chara);

/**
 * @brief Entering a character string with deletion of input and output buffers
 *
 * @param strings Memory address of the character string allocated and to be written
 * @param nbChar Maximum number of characters the string must contain
 */
void scanString     (char** strings, int nbChara);


#endif // !SCAN