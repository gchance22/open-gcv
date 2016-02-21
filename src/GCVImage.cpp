//
//  gcvImage.cpp
//  
//
//  Created by Graham Chance on 2/20/16.
//
//

#include "GCVImage.hpp"


namespace gcv  {
    
    Mat GCVImage::loadMat() {
        return imread(this->imgPath);
    }
    
    void GCVImage::show() {
        Mat dst;
        // resize so it fits the window well.
        resize(this->loadMat(), dst, Size(1024, 768), 0, 0, INTER_CUBIC);
        showMat(dst,this->imgPath);
    }
    
}