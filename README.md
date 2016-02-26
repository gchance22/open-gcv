# open-gcv
Making opencv a little less painful.

##Uses

####GCVImage
GCVImage is a helpful way to represent an image, without having it take up the memory a Mat does. 
```c++
gcv:GCVImage image = new GCVImage("filepath");
// Get the image's matrix
cv::Mat matrix = image.loadMat();

// Show image
image.show();

// Or if you want to load the matrix on initialization:
gcv:GCVImage image2 = new GCVImage("filepath", true);

image2.matrixIsLoaded(); // true

```
####Utilities
gcv_utilities.hpp contains helpful functions for when working with opencv. 
#####Examples
```c++
// Displays the matrix and waits for key press
gcv::showMat(mat, "image name");

// Shows the image at the given path and waits for key press.
gcv::showImageAtPath(string pathToImg);

// Get all the images in the given directory:
bool displayImages = false;
bool loadMats = false;
vector<GCVImage> images = loadImagesFromDirectory("./photos", displayImages, loadMats);
```

#####All files are compiled into the dynamic library, "libgcv".
