//
//  gcv_utilities.cpp
//
//
//  Created by Graham Chance on 2/18/16.
//
//


#include "gcv_utilities.hpp"

using namespace std;
using namespace cv;

namespace gcv {

    Mat croppedImage(Mat img, int xstart,int ystart,int width,int height) {
        Rect croppedArea(xstart, ystart, width, height);
        return img(croppedArea);
    }

    int numImagesInDirectory(string dirname) {
        printf("Accessing directory %s\n\n", dirname.c_str());
        DIR *dirp;
        struct dirent *dp;
        // open the directory
        dirp = opendir( dirname.c_str() );
        if( dirp == NULL ) {
            printf("Cannot open directory %s\n", dirname.c_str());
            return -1;
        }

        // loop over the contents of the directory, looking for images
        // Get number of images first
        int numImages = 0;
        while( (dp = readdir(dirp)) != NULL ) {
            if( strstr(dp->d_name, ".jpg") ||
               strstr(dp->d_name, ".png") ||
               strstr(dp->d_name, ".ppm") ||
               strstr(dp->d_name, ".tif") ) {
                numImages++;
            }
        }
        // close the directory
        closedir(dirp);
        cout << numImages;
        cout << " images in directory" << endl;
        return numImages;
    }

    vector<string> imageNamesInDirectory(string dirname) {
        printf("Accessing directory %s\n\n", dirname.c_str());
        DIR *dirp;
        struct dirent *dp;
        vector<string> names;
        // open the directory
        dirp = opendir( dirname.c_str() );
        if( dirp == NULL ) {
            printf("Cannot open directory %s\n", dirname.c_str());
            return names;
        }
        // Now add image names to vector
        int i = 0;
        while( (dp = readdir(dirp)) != NULL ) {
            if( strstr(dp->d_name, ".jpg") ||
               strstr(dp->d_name, ".png") ||
               strstr(dp->d_name, ".ppm") ||
               strstr(dp->d_name, ".tif") ) {
                names.push_back(dp->d_name);
                //cout << dest[i] << endl;
                i++;
            }
        }

        // close the directory
        closedir(dirp);
        return names;
    }

    vector<GCVImage> loadImagesFromDirectory(string dirname, bool display, bool loadMats) {
        vector<GCVImage> images;
        vector<string> imageNames = imageNamesInDirectory(dirname);
        for (int i=0; i<imageNames.size();i++) {
            // read the image
            string path = dirname + "/" + imageNames[i];
            images.push_back(GCVImage(path,imageNames[i],loadMats));
        }
        if (display) {
        for (int i=0; i<images.size();i++) {
                namedWindow(images[i].name, CV_WINDOW_NORMAL);
                imshow("", images[i].getMat());
                waitKey(0);
                destroyWindow(images[i].name);
            }
        }
        return images;
    }

    void showMat(Mat img, string displayname) {
        printf("showing image \"%s\"\n",displayname.c_str());;
        namedWindow(displayname, CV_WINDOW_NORMAL);
        imshow(displayname, img);
        waitKey(0);
        destroyWindow(displayname);
    }

    int showImageAtPath(string pathToImg) {
        Mat img = imread(pathToImg);
        // test if the read was successful
        if(img.data == NULL) {
            printf("Unable to read image %s\n", pathToImg.c_str());
            return -1;
        }
        showMat(img,pathToImg);
        return 0;
    }
}
