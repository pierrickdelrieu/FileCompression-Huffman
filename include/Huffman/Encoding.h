#ifndef ENCODING
#define ENCODING

#include "../../include/Huffman/Dictionary.h"

extern void    encodingFile    (DicoTree tree);

extern char*   getCodeLetter   (DicoTree tree, char letter);

#endif // !ENCODING
