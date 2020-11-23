#ifndef FILE_MANAGMENT
#define FILE_MANAGMENT


#define SIZE_BINARY 8 

#define ASCII_INIT_NUMBER 48

typedef struct Binary {
    int* nb;
} Binary;


extern Binary* createBinaryNumber  (int size);

extern Binary* convertIntToBinary  (int value);


extern void    createBinaryFileOfFileToCompress    (void);

extern int     numberCharInFile                    (char* filePath);

extern void    initFileToCompress                  (char *txt);

extern float   ratioCompression                    (void);



#endif // !FILE_MANAGMENT
