//
// GCVImage.hpp
//
//
//  Created by Graham Chance on 2/20/16.
//
//

#ifndef GCVImage_hpp
#define GCVImage_hpp

#include <stdio.h>
#include "gcv_utilities.hpp"
#include <string>
#include "opencv2/opencv.hpp"

using namespace cv;

namespace gcv {

    class GCVImage
    {
    public:

        /**
         *  Default Constructor.
         *
         *  @return A new GCVImage with an empty image path.
         */
        GCVImage() { }

        /**
         *  Constructor.
         *
         *  @param filepath Path to the image file.
         *  @param name A name describing the image.
         *  @param loadMat Whether the matrix should be loaded.
         *
         *  @return A new GCVImage with the given image path.
         */
        GCVImage(string filepath, string name = "", bool loadMat = false)
        : imgPath(filepath) {

            if (name == "") {
                name = filepath;
            }

            if (loadMat) {
                this->loadMat(true);
            } else {
                matrix = Mat();
            }

        }

        /**
         *  Path to the image file.
         */
        string imgPath;

        /**
         *  A name describing the image.
         */
        string name;

        /**
         *  The matrix for the image.
         *  If loadMat() has not been called, it will be NULL;
         */
         Mat matrix;

        /**
         *  Allows for matrix retrieval only when needed.
         *
         *  @param persist Whether the gcvimage should hold onto the Mat.
         *
         *  @return The Mat at the GCVImage's path.
         */
        Mat loadMat(bool persist = false);

        /**
         *  Displays the image until key-press.
         */
        void show();

        /** A way to check whether the matrix has been loaded.
         *
         *  @return Whether matrix is not null.
         */
         bool matrixIsLoaded();

    };
}

#endif /* gcvImage_hpp */
