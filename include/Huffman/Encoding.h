#ifndef ENCODING
#define ENCODING

#include "../../include/Huffman/Dictionary.h"

void encodingFile(DicoTree tree);
char* getCodeLetter(DicoTree tree, char letter);

#endif // !ENCODING
