#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Encoding.h"
#include "../../include/Huffman/Dictionary.h"



void EncodingFile(DicoTree* Tree)
{
    FILE* FileToCompress = NULL;
    FILE* HuffmanCompression = NULL;

    char lettre,copie;


    FileToCompress = fopen("FileToCompress.txt","r");
    HuffmanCompression = fopen("HuffmanCompression.txt","w");
    if ((FileToCompress!=NULL) && (HuffmanCompression!=NULL))
    {
        do {
            lettre = fgetc(FileToCompress);
            SearchLetter(lettre, Tree, HuffmanCompression);
        }while (lettre!=EOF);

        fclose(FileToCompress);
        fclose(HuffmanCompression);


        else
        {
            printf("Erreur , le fichier n'a pas pu etre ouvert");
        }
    }






    int SearchLetter(char lettre,DicoTree* Tree,FILE* HuffmanCompression)
    {
        if ((Tree->letter)== lettre)
        {
            fputs(Tree->code,HuffmanCompression);
            return 0;
        }
        else if (Tree == NULL)
        {
            return 0;
        }
        else
        {
            SearchLetter(lettre,Tree->left,HuffmanCompression);
            SearchLetter(lettre,Tree->right,HuffmanCompression);

        }

    }