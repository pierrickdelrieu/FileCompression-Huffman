#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Encoding.h"
#include "../../include/Huffman/Dictionary.h"

void encodage_texte_dico(void){
    FILE* FileToCompress = NULL;
    FILE* HuffmanCompression = NULL;
    FILE* HuffmanDictionary = NULL;
    int jason;
    char lettre;


    FileToCompress = fopen("FileToCompress.txt","r");
    HuffmanDictionary = fopen("HuffmanDictionary.txt","r");
    HuffmanCompression = fopen("HuffmanCompression.txt","w");
    if ((FileToCompress != NULL ) &&  (HuffmanDictionary!= NULL) && (HuffmanCompression !=NULL)){

        do {  lettre = fgetc(FileToCompress);
            printf("%c",lettre);
            //while (lettre!=EOF){
            //lettre = fgetc(FileToCompress);
            if (lettre!= '\n'){
                char dico = fgetc(HuffmanDictionary);
                if (dico == lettre && (dico!=EOF)) {
                    //printf("test");
                    fseek(HuffmanDictionary,1,SEEK_CUR);
                    do{
                        jason = fgetc(HuffmanDictionary);
                        fputc(jason,HuffmanCompression);
                    }while((jason != EOF) && (jason !='\n'));
                    rewind(HuffmanDictionary);
                }
                else{
                    do{
                        //printf("oui");
                        printf("%c",dico);
                        dico= fgetc(HuffmanDictionary);
                        if  ((dico == lettre) && (dico!=EOF)) {
                            fseek(HuffmanDictionary,1,SEEK_CUR);
                            do{
                                jason = fgetc(HuffmanDictionary);
                                fputc(jason,HuffmanCompression);
                            }while((jason != EOF) && (jason !='\n'));
                            rewind(HuffmanDictionary);
                        }
                    }while ((dico!=lettre)&& (dico!=EOF)&& (dico!='\n'));

                }

            }}while (lettre!=EOF);



        fclose(FileToCompress);
        fclose(HuffmanCompression);
        fclose(HuffmanDictionary);
    }}
/* else {
     displayErrorMessageOpenFile();
 }*/