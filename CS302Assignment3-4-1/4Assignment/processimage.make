processimage.bin: processImageMain.o image.o ReadImageHeader.o ReadImage.o WriteImage.o DFSstack.o BFSqueue.o RegionType.o PixelType.o
	g++ -o processimage.bin processImageMain.o image.o ReadImageHeader.o ReadImage.o WriteImage.o DFSstack.o BFSqueue.o RegionType.o PixelType.o

processImageMain.o: processImageMain.cpp image.h RegionList.h RegionType.h PixelList.h PixelType.h NodeType.h
	g++ -c processImageMain.cpp

ReadImageHeader.o: image.h ReadImageHeader.cpp
	g++ -c ReadImageHeader.cpp

ReadImage.o: image.h ReadImage.cpp
	g++ -c ReadImage.cpp

WriteImage.o: image.h WriteImage.cpp
	g++ -c WriteImage.cpp

image.o: image.h image.cpp
	g++ -c image.cpp

DFSstack.o: DFSstack.h DFSstack.cpp Node/node.h
	g++ -c DFSstack.cpp

BFSqueue.o: BFSqueue.h BFSqueue.cpp Node/node.h
	g++ -c BFSqueue.cpp

RegionType.o: RegionType.h RegionType.cpp
	g++ -c RegionType.cpp

PixelType.o: PixelType.h PixelType.cpp
	g++ -c PixelType.cpp
