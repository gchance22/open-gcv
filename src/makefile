# OSX compiler
CC = clang++

CXX = $(CC)

# OSX include paths
CFLAGS = -I/usr/local/Cellar/opencv/2.4.12_2/include -I../include

CXXFLAGS = $(CFLAGS)

# OSX Library paths
LDFLAGS = -L/usr/local/lib -L/usr/local/Cellar/opencv3/3.1.0_1/lib 

# OSX libraries
LDLIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_objdetect 


BINDIR = ../bin

all: utilities gcvimage libgcv

utilities: gcv_utilities.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)

gcvimage: GCVImage.o gcv_utilities.o
	$(CC) $^ -dynamiclib -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS) 

libgcv: gcv_utilities.o gcvimage.o
	g++ -dynamiclib -undefined suppress -flat_namespace gcvimage.o gcv_utilities.o -o ../lib/libgcv.dylib
 


clean:
	rm -f *.o *~ 


