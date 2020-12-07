/**
 * @file Encoding.h
 * @author Raphaël Cadillat
 * @brief Encoding function
 * @version 0.1
 * @date 23-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef ENCODING
#define ENCODING

#include "../../include/Huffman/Dictionary.h"
/**
 * @brief Writing binary numbers corresponding to each letter of the file to compress
 *
 * @param tree Tree containing each letter and its code
 */
void encodingFile(DicoTree tree);

/**
 * @brief Get the Code corresponding to a letter
 *
 * @param tree
 * @param letter Researched letter
 * @return char* Code corresponding to a letter
 */
char* getCodeLetter(DicoTree tree, char letter);

#endif // !ENCODING
