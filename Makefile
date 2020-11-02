OUTPUT=binaires/
COMPILER=gcc
EXEC= compressor


IHMCOMPRESSOR = objets/IHMCompressor/Menu.o objets/IHMCompressor/Scan.o objets/IHMCompressor/Show.o

HUFFMAN = objets/Huffman/Encoding.o objets/Huffman/Decoding.o objets/Huffman/Dictionary.o objets/Huffman/HuffmanTree.o

FILE_MANAGMENT = objets/FileManagment.o

OBJS = objets/main.o $(IHMCOMPRESSOR) $(HUFFMAN) $(FILE_MANAGMENT)


compressor: $(OBJS)
	$(COMPILER) $(OBJS) -o $(OUTPUT)/$(EXEC)


objets/main.o : include/FileManagment.h \
				sources/main.c
	$(COMPILER) -c -g -Wall sources/main.c -o objets/main.o
	

#IHMCOMPRESSOR
objets/IHMCompressor/Menu.o : include/IHMCompressor/Menu.h \
								sources/IHMCompressor/Menu.c
	$(COMPILER) -c -g -Wall sources/IHMCompressor/Menu.c -o objets/IHMCompressor/Menu.o

objets/IHMCompressor/Scan.o : include/IHMCompressor/Scan.h \
								sources/IHMCompressor/Scan.c
	$(COMPILER) -c -g -Wall sources/IHMCompressor/Scan.c -o objets/IHMCompressor/Scan.o

objets/IHMCompressor/Show.o : include/IHMCompressor/Show.h \
								sources/IHMCompressor/Show.c
	$(COMPILER) -c -g -Wall sources/IHMCompressor/Show.c -o objets/IHMCompressor/Show.o



#HUFFMAN
objets/Huffman/Decoding.o : include/Huffman/Decoding.h  \
								include/IHMCompressor/Show.h  \
								include/Huffman/Dictionary.h  \
								sources/Huffman/Decoding.c
	$(COMPILER) -c -g -Wall sources/Huffman/Decoding.c -o objets/Huffman/Decoding.o

objets/Huffman/Encoding.o : include/Huffman/Encoding.h  \
								include/IHMCompressor/Show.h  \
								include/Huffman/Dictionary.h  \
								sources/Huffman/Encoding.c
	$(COMPILER) -c -g -Wall sources/Huffman/Encoding.c -o objets/Huffman/Encoding.o

objets/Huffman/Dictionary.o : include/Huffman/Dictionary.h  \
								include/IHMCompressor/Show.h  \
								sources/Huffman/Dictionary.c
	$(COMPILER) -c -g -Wall sources/Huffman/Dictionary.c -o objets/Huffman/Dictionary.o

objets/Huffman/HuffmanTree.o : include/Huffman/HuffmanTree.h  \
								include/IHMCompressor/Show.h  \
								sources/Huffman/HuffmanTree.c
	$(COMPILER) -c -g -Wall sources/Huffman/HuffmanTree.c -o objets/Huffman/HuffmanTree.o



#FILE_MANAGMENT
objets/FileManagment.o : include/FileManagment.h  \
								include/IHMCompressor/Show.h \
								sources/FileManagment.c
	$(COMPILER) -c -g -Wall sources/FileManagment.c -o objets/FileManagment.o




clean:
	rm $(OBJS)
	rm -rf $(OUTPUT)/$(EXEC)

run:
	./$(OUTPUT)$(EXEC)
