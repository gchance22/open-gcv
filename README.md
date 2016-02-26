# open-gcv
Making opencv a little less painful.

##Uses

####GCVImage
GCVImage is a helpful way to represent an image, without having it take up the memory a Mat does. 
```c++
// Get the image's matrix
cv::Mat matrix = image.loadMat();

// Show image
image.show();
```
####Utilities
gcv_utilities.hpp contains helpful functions for when working with opencv. 
#####Examples
```c++
// Displays the matrix and waits for key press
gcv::showMat(mat, "image name");

// Shows the image at the given path and waits for key press.
gcv::showImageAtPath(string pathToImg);
```

#####All files are compiled into the dynamic library, "libgcv".
