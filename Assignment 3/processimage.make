processimage.bin: processImageMain.o image.o ReadImageHeader.o ReadImage.o WriteImage.o
	g++ -o processimage.bin processImageMain.o image.o ReadImageHeader.o ReadImage.o WriteImage.o

processImageMain.o: processImageMain.cpp image.h stack.cpp
	g++ -c processImageMain.cpp 

ReadImageHeader.o: image.h ReadImageHeader.cpp
	g++ -c ReadImageHeader.cpp

ReadImage.o: image.h ReadImage.cpp
	g++ -c ReadImage.cpp

WriteImage.o: image.h WriteImage.cpp
	g++ -c WriteImage.cpp

image.o: image.cpp image.h
	g++ -c image.cpp

stack.o: stack.cpp node.h
	g++ -c stack.cpp

queue.o: queue.cpp node.h
	g++ -c queue.cpp