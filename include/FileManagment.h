#ifndef FILE_MANAGMENT
#define FILE_MANAGMENT

#define SIZE_BINARY 8 // un nopbre bianire est codée sur 8 bits
#define ASCII_INIT_NUMBER 48


typedef struct Binary {
    int* nb;
} Binary;

Binary* create_binary_number();
Binary* convert_int_to_binary(int value);


void create_binary_file_of_FileToCompress();


int number_char_in_file(char* filePath);



#endif // !FILE_MANAGMENT
