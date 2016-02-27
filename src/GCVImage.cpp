//
//  gcvimage.cpp
//
//
//  Created by Graham Chance on 2/20/16.
//
//

#include "gcvimage.hpp"
#include "gcv_utilities.hpp"

namespace gcv  {

    Mat GCVImage::getMat(bool persist) {
        if (this->matrixIsLoaded()) {
            return this->matrix;
        }
        Mat mat = imread(this->imgPath);
        if (persist) {
            this->matrix = mat;
        }

        if (mat.data == NULL) {
            printf("Could not load matrix for image at path %s\n",this->imgPath.c_str());
        }

        return mat;
    }

    void GCVImage::show() {
        Mat dst;
        // resize so it fits the window well.
        resize(this->getMat(), dst, Size(1024, 768), 0, 0, INTER_CUBIC);
        showMat(dst,this->name);
    }

    string GCVImage::getPath() {
        return this->imgPath;
    }

    bool GCVImage::matrixIsLoaded() {
        return !(this->matrix.empty());
    }

}
