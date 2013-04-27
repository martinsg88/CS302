processImage.bin: processImageMain.o ReadImageHeader.o ReadImage.o WriteImage.o RGB.o
	g++ -o processImage.bin processImageMain.o ReadImageHeader.o ReadImage.o WriteImage.o RGB.o

processImageMain.o: processImageMain.cpp image.h 
	g++ -c processImageMain.cpp

ReadImageHeader.o: ReadImageHeader.cpp image.h
	g++ -c ReadImageHeader.cpp

ReadImage.o: ReadImage.cpp image.h
	g++ -c ReadImage.cpp

WriteImage.o: WriteImage.cpp image.h
	g++ -c WriteImage.cpp

RGB.o: RGB.h
	g++ -c RGB.cpp
