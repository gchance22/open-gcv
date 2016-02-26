# OSX compiler
CC = clang++

CXX = $(CC)

# OSX include paths
CFLAGS =  -I../include -I./Catch -I/usr/local/Cellar/opencv/2.4.12_2/include -I../include -I/usr/local/Cellar/opencv3/3.1.0_1/include

CXXFLAGS = $(CFLAGS)

# OSX Library paths
LDFLAGS = -L.. -L/usr/local/lib -L/usr/local/Cellar/opencv3/3.1.0_1/lib

# OSX libraries
LDLIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_objdetect -lgcv


tests: gcvimage_tests

gcvimage_tests: gcvimage_tests.o 
	$(CC) $^ -o gcvimage_tests $(LDFLAGS) $(LDLIBS)


clean:
	rm -f *.o *~
