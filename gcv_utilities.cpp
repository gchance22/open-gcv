//
//  gcvhelpers.cpp
//  
//
//  Created by Graham Chance on 2/18/16.
//
//


#include "gcv_utilities.hpp"


using namespace std;
using namespace cv;


namespace gcv {
    
    
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
    
    
    int imageNamesInDirectory(string dest[], string dirname) {
        printf("Accessing directory %s\n\n", dirname.c_str());
        DIR *dirp;
        struct dirent *dp;
        // open the directory
        dirp = opendir( dirname.c_str() );
        if( dirp == NULL ) {
            printf("Cannot open directory %s\n", dirname.c_str());
            return -1;
        }
        // Now add image names to array
        int i = 0;
        while( (dp = readdir(dirp)) != NULL ) {
            if( strstr(dp->d_name, ".jpg") ||
               strstr(dp->d_name, ".png") ||
               strstr(dp->d_name, ".ppm") ||
               strstr(dp->d_name, ".tif") ) {
                dest[i] = dp->d_name;
                cout << dest[i] << endl;
                i++;
            }
        }
        
        // close the directory
        
        closedir(dirp);
        return 0;
    }
    
    void loadImagesFromDirectory(Mat dest[], int nimages, string dirname, bool display) {
        printf("Attempting to load %i images\n",nimages);
        if (nimages==0) { return; }
        string *imageNames = new string[nimages];
        gcv::imageNamesInDirectory(imageNames,dirname);
        for (int i=0; i<nimages;i++) {
            // read the image
            string path = dirname + "/" + imageNames[i];
            Mat img = imread(path);
            // test if the read was successful
            if(img.data == NULL) {
                printf("Unable to read image %s\n", path.c_str());
                break;
            }
            
            dest[i] = img;
            if (display) {
                namedWindow(imageNames[i], CV_WINDOW_NORMAL);
                imshow("", dest[i]);
                waitKey(0);
                destroyWindow(imageNames[i]);
            }
            
        }
        printf("%i images loaded into array\n",nimages);
        delete[] imageNames;
    }
    
    
    void showMat(Mat img, string displayname) {
        cout << "showing image" << endl;
        namedWindow(displayname, CV_WINDOW_NORMAL);
        imshow(displayname, img);
        waitKey(0);
        destroyWindow(displayname);
    }
    
    int showImage(string pathToImg) {
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

//
//
//int main(int argc, char *argv[]) {
//    
//    char dirname[256];
//    
//    
//    // by default, look at the current directory
//    strcpy(dirname, ".");
//    
//    // if the user provided a directory path, use it
//    if(argc > 1) {
//        strcpy(dirname, argv[1]);
//    }
//    
//    //    char imageNames[numImagesInDirectory(dirname)][32];
//    //    imageNamesInDirectory(imageNames,dirname);
//    int numImages = gcv::numImagesInDirectory(dirname);
//    Mat *imgs = new Mat[numImages];
//    gcv::loadImagesFromDirectory(imgs,numImages,dirname,false);
//    //double similarity = compareImages(imgs[0],imgs[1],CV_COMP_CORREL);
//    //printf("similarity: %f",similarity);
//    
//    
//    gcv::showImage(imgs[0],"Original Image");
//
//    return 0;
//    
//}

