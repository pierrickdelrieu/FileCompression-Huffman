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




Binary* create_binary_number    (void);
Binary* convert_int_to_binary   (int value);


void    create_binary_file_of_FileToCompress    (void);
int     number_char_in_file                     (char* filePath);



#endif // !FILE_MANAGMENT
