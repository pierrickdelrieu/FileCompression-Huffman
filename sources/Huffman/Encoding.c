#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Encoding.h"
#include "../../include/Huffman/Dictionary.h"

#include <stdio.h>
#include <stdlib.h>


void encoding_text(void)
{
    FILE* FileToCompress = NULL;
    FILE* HuffmanCompression = NULL;
    FILE* HuffmanDictionary = NULL;

    char letter,dictionary,copy;


    FileToCompress = fopen("FileToCompress.txt","r");
    HuffmanDictionary = fopen("HuffmanDictionary.txt","r");
    HuffmanCompression = fopen("HuffmanCompression.txt","w+");
    if ((FileToCompress != NULL ) &&  (HuffmanDictionary!= NULL) && (HuffmanCompression !=NULL))
    {

        do
        {
            letter = fgetc(FileToCompress);

            //while (letter!=EOF){
            //letter = fgetc(FileToCompress);
            if (letter!= '\n')
            {
                dictionary = fgetc(HuffmanDictionary);
                if (dictionary == letter && (dictionary!=EOF))
                {

                    fseek(HuffmanDictionary,1,SEEK_CUR);
                    do
                    {
                        copy = fgetc(HuffmanDictionary);
                        fputc(copy,HuffmanCompression);


                    }
                    while((copy != EOF) && (copy !='\n'));
                    rewind(HuffmanDictionary);
                    copy= fgetc(HuffmanDictionary);


                }
                else
                {
                    do  //Parcours le dictionnaire tant qu'il n'est pas fini ou qu'on a pas trouvé la letter
                    {

                        printf("%c",dictionary);
                        dictionary=fgetc(HuffmanDictionary);
                        if  ((dictionary == letter) && (dictionary!=EOF))            ///  c KC.
                        {


                            fseek(HuffmanDictionary,1,SEEK_CUR);
                            do
                            {
                                copy = fgetc(HuffmanDictionary);
                                // if (copy =! '\n'){
                                fputc(copy,HuffmanCompression);//}

                            }
                            while((copy != EOF) && (copy !='\n'));
                            rewind(HuffmanDictionary);
                        }
                    }
                    while ((dictionary!=letter)&& (dictionary!=EOF));

                }

            }
        }
        while ((letter!=EOF)&&(letter!='\n'));



        fclose(FileToCompress);
        fclose(HuffmanCompression);
        fclose(HuffmanDictionary);
    }
}
/* else {
     displayErrorMessageOpenFile();
 }*/

