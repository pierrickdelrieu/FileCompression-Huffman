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




Binary* createBinaryNumber  (int size);
Binary* convertIntToBinary  (int value);


void    createBinaryFileOfFileToCompress    (void);
int     numberCharInFile                    (char* filePath);



#endif // !FILE_MANAGMENT
