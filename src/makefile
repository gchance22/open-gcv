# OSX compiler
CC = clang++

CXX = $(CC)

# OSX include paths
CFLAGS = -I/usr/local/Cellar/opencv/2.4.12_2/include -I../include

CXXFLAGS = $(CFLAGS)

# OSX Library paths
LDFLAGS = -L/usr/local/lib -L/usr/local/Cellar/opencv3/3.1.0_1/lib -L../lib

# OSX libraries
LDLIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_objdetect 


BINDIR = ../bin

all: utilities libgcv_utilities gcvimage libgcv_image

utilities: gcv_utilities.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)

gcvimage: GCVImage.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS) -lgcv_utilities

libgcv_utilities: gcv_utilities.o 
	g++ -dynamiclib -undefined suppress -flat_namespace gcv_utilities.o -o ../lib/libgcv_utilities.dylib

libgcv_image: gcvimage.o 
	g++ -dynamiclib -undefined suppress -flat_namespace gcvimage.o -o ../lib/libgcv_image.dylib

clean:
	rm -f *.o *~ 


