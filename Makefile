OUTPUT=binaires/
OBJECTS= objects/
SOURCES= sources/
INCLUDE= include/
COMPILER=gcc
EXEC= compressor


IHMCOMPRESSOR = $(OBJECTS)IHMCompressor/Menu.o $(OBJECTS)IHMCompressor/Scan.o $(OBJECTS)IHMCompressor/Show.o

HUFFMAN = $(OBJECTS)Huffman/Encoding.o $(OBJECTS)Huffman/Decoding.o $(OBJECTS)Huffman/Dictionary.o $(OBJECTS)Huffman/HuffmanTree.o

DATASTRUCTURES = $(OBJECTS)DataStructures/LinkedList.o $(OBJECTS)DataStructures/File.o

FILE_MANAGMENT = $(OBJECTS)FileManagment.o

OBJS = $(OBJECTS)main.o $(IHMCOMPRESSOR) $(HUFFMAN) $(FILE_MANAGMENT) $(DATASTRUCTURES) tests/tests.o


compressor: $(OBJS)
	$(COMPILER) $(OBJS) -o $(OUTPUT)/$(EXEC)


$(OBJECTS)main.o : $(INCLUDE)FileManagment.h \
					$(INCLUDE)/Huffman/Encoding.h  \
					$(INCLUDE)/Huffman/Decoding.h  \
					$(INCLUDE)/Huffman/Dictionary.h  \
					tests/tests.h \
				$(SOURCES)main.c
	$(COMPILER) -c -g -Wall $(SOURCES)main.c -o $(OBJECTS)main.o
	

#IHMCOMPRESSOR
$(OBJECTS)IHMCompressor/Menu.o : $(INCLUDE)IHMCompressor/Menu.h \
								$(SOURCES)IHMCompressor/Menu.c
	$(COMPILER) -c -g -Wall $(SOURCES)IHMCompressor/Menu.c -o $(OBJECTS)IHMCompressor/Menu.o

$(OBJECTS)IHMCompressor/Scan.o : $(INCLUDE)IHMCompressor/Scan.h \
								$(SOURCES)IHMCompressor/Scan.c
	$(COMPILER) -c -g -Wall $(SOURCES)IHMCompressor/Scan.c -o $(OBJECTS)IHMCompressor/Scan.o

$(OBJECTS)IHMCompressor/Show.o : $(INCLUDE)IHMCompressor/Show.h \
								$(SOURCES)IHMCompressor/Show.c
	$(COMPILER) -c -g -Wall $(SOURCES)IHMCompressor/Show.c -o $(OBJECTS)IHMCompressor/Show.o



#HUFFMAN
$(OBJECTS)Huffman/Decoding.o : $(INCLUDE)Huffman/Decoding.h  \
								$(INCLUDE)IHMCompressor/Show.h  \
								$(INCLUDE)Huffman/Dictionary.h  \
								$(SOURCES)Huffman/Decoding.c
	$(COMPILER) -c -g -Wall $(SOURCES)Huffman/Decoding.c -o $(OBJECTS)Huffman/Decoding.o

$(OBJECTS)Huffman/Encoding.o : $(INCLUDE)Huffman/Encoding.h  \
								$(INCLUDE)IHMCompressor/Show.h  \
								$(INCLUDE)Huffman/Dictionary.h  \
								$(SOURCES)Huffman/Encoding.c
	$(COMPILER) -c -g -Wall $(SOURCES)Huffman/Encoding.c -o $(OBJECTS)Huffman/Encoding.o

$(OBJECTS)Huffman/Dictionary.o : $(INCLUDE)Huffman/Dictionary.h  \
								$(INCLUDE)IHMCompressor/Show.h  \
								$(SOURCES)Huffman/Dictionary.c
	$(COMPILER) -c -g -Wall $(SOURCES)Huffman/Dictionary.c -o $(OBJECTS)Huffman/Dictionary.o

$(OBJECTS)Huffman/HuffmanTree.o : $(INCLUDE)Huffman/HuffmanTree.h  \
								$(INCLUDE)DataStructures/File.h  \
								$(INCLUDE)IHMCompressor/Show.h  \
								$(SOURCES)Huffman/HuffmanTree.c
	$(COMPILER) -c -g -Wall $(SOURCES)Huffman/HuffmanTree.c -o $(OBJECTS)Huffman/HuffmanTree.o



#FILE_MANAGMENT
$(OBJECTS)FileManagment.o : $(INCLUDE)FileManagment.h  \
								$(INCLUDE)IHMCompressor/Show.h \
								$(SOURCES)FileManagment.c
	$(COMPILER) -c -g -Wall $(SOURCES)FileManagment.c -o $(OBJECTS)FileManagment.o


#DATA_STRUCTURES
$(OBJECTS)DataStructures/LinkedList.o : $(INCLUDE)DataStructures/LinkedList.h  \
								$(INCLUDE)IHMCompressor/Show.h \
								$(SOURCES)DataStructures/LinkedList.c
	$(COMPILER) -c -g -Wall $(SOURCES)DataStructures/LinkedList.c -o $(OBJECTS)DataStructures/LinkedList.o

$(OBJECTS)DataStructures/File.o : $(INCLUDE)DataStructures/File.h  \
								$(INCLUDE)DataStructures/LinkedList.h  \
								$(SOURCES)DataStructures/File.c
	$(COMPILER) -c -g -Wall $(SOURCES)DataStructures/File.c -o $(OBJECTS)DataStructures/File.o




#TESTS
tests/tests.o : tests/tests.h  \
				$(INCLUDE)FileManagment.h  \
				tests/tests.c
	$(COMPILER) -c -g -Wall tests/tests.c -o tests/tests.o






clean:
	rm $(OBJS)
	rm -rf $(OUTPUT)/$(EXEC)

run:
	./$(OUTPUT)$(EXEC)
