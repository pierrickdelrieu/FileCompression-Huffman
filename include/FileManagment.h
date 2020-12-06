/**
 * @file FileManagment.c
 * @author Pierrick Delrieu
 * @brief Converting a Text File to Binary Text and Counting Items in a File
 * @details Part 1 of project
 * @version 0.1
 * @date 01-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef FILE_MANAGMENT
#define FILE_MANAGMENT


///@brief Number of digits of a classic binary number
#define SIZE_BINARY 8 

///@brief character (0) -> decimal (48) according to the ascii table
#define ASCII_INIT_NUMBER 48



/// @brief Array of integers to represent a number in binary
typedef struct Binary {
    int* nb;
} Binary;


/**
 * @brief Memory allocation of the Binary structure and of the 1D array representing the bytes
 * 
 * @param size Array size, number of bits used to represent the number
 * @return Binary* Pointer to allocated structure
 */
Binary* createBinaryNumber  (int size);

/**
 * @brief Converting integer to binary number (0 and 1)
 * @details In the table the 0 and 1 are represented in decimal form either according to the ascii table 
 * charactere(0) -> decimal(48) and charactere(1) -> decimal(49)
 * 
 * @param value Integer to convert
 * @return Binary* 1D array of size 8. Each box represents one byte.
 */
Binary* convertIntToBinary  (int value);

/**
 * @brief Creation of a binary number file 'BinaryFile.txt' containing the equivalent of the character file 'FileToCompress'
 * @details 'fileToCompress' is open in read-only mode because we don't need to modify it
 * 'binaryFile' is open read and write
 * 
 */
void    createBinaryFileOfFileToCompress    (void);

/**
 * @brief Counting the number of characters in a file
 * 
 * @param filePath Character string containing the path (from the main folder) to the file to be processed
 * @return int Number of characters in the file
 */
int     numberCharInFile                    (char* filePath);

/**
 * @brief Initialization of the contents of the file to compress in order to know the noramlement results obtained
 * 
 */
void    initFileToCompress                  (char *txt);

float   ratioCompression                    (void);



#endif // !FILE_MANAGMENT
