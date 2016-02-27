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

    Mat GCVImage::loadMat(bool persist) {
        if (this->matrixIsLoaded()) {
            return this->matrix;
        }
        Mat mat = imread(this->imgPath);
        if (persist) {
            this->matrix = mat;
        }
        return mat;
    }

    void GCVImage::show() {
        Mat dst;
        // resize so it fits the window well.
        resize(this->loadMat(), dst, Size(1024, 768), 0, 0, INTER_CUBIC);
        showMat(dst,this->name);
    }

    bool GCVImage::matrixIsLoaded() {
        return !(this->matrix.empty());
    }

}
