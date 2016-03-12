//
//  gcv_utilities.hpp
//
//
//  Created by Graham Chance on 2/18/16.
//
//

#ifndef gcv_utilities_hpp
#define gcv_utilities_hpp

#include "opencv2/opencv.hpp"
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <string>
#include "GCVImage.hpp"

using namespace cv;
using namespace std;

namespace gcv {

    /**
     *  Crops an image Mat. Note: Does not copy the data.
     *
     *  @param img    Mat to crop.
     *  @param xstart The starting column.
     *  @param ystart The starting row.
     *  @param width  How many columns the cropped image should have.
     *  @param height How many rows the cropped image should have.
     *
     *  @return The cropped Mat.
     */
    Mat croppedImage(Mat img, int xstart,int ystart,int width,int height);

    /**
     *  Counts the number of images a directory.
     *
     *  @param dirname Directory to search.
     *
     *  @return The number of image files. -1 if failed to open directory.
     */
    int numImagesInDirectory(string dirname);

    /**
     *  Gets the names of all the images in a directory.
     *
     *  @param dirname The directory to search.
     *
     *  @return Names of all the images found.
     */
    vector<string> imageNamesInDirectory(string dirname);

    /**
     *  Loads all images in a directory.
     *
     *  @param dirname The name of the directory.
     *  @param display Whether to display all of the found images.
     *  @param loadMats Whether the GCVImages should load their matrices.
     *
     *  @return A vector containing the images as GCVimages
     */
    vector<GCVImage> loadImagesFromDirectory(string dirname, bool display, bool loadMats);

    /**
     *  Displays an image.
     *
     *  @param img         The Mat to display.
     *  @param displayname The name to appear on the window.
     */
    void showMat(Mat img, string displayname);

    /**
     *  Shows an image.
     *
     *  @param pathToImg The file path of the image to show.
     *
     *  @return -1 if failed, otherwise 0.
     */
    int showImageAtPath(string pathToImg);

}

#endif /* gcv_utilities_hpp */
