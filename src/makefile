# OSX compiler
CC = clang++

CXX = $(CC)

# OSX include paths
CFLAGS = -I/usr/local/Cellar/opencv/2.4.12_2/include 

CXXFLAGS = $(CFLAGS)

# OSX Library paths
LDFLAGS = -L/usr/local/lib -L/usr/local/Cellar/opencv3/3.1.0_1/lib -L../bin

# OSX libraries
LDLIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_objdetect -lgcv


BINDIR = ../bin

all: utilities gcvimage gcv

utilities: gcv_utilities.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)

gcvimage: GCVImage.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)


gcv: gcv_utilities.o GCVImage.o
	g++ -dynamiclib -undefined suppress -flat_namespace GCVImage.o gcv_utilities.o -o ../bin/libgcv.dylib


clean:
	rm -f *.o *~ 


