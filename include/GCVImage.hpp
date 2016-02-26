//
//  gcvImage.hpp
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
    
    
    /// This class models an image, although it really only contains the image path, so an instance does not take much memory.
    class GCVImage
    {
    public:
        
        /**
         *  Default Constructor.
         *
         *  @param "" Empty path.
         *
         *  @return A new GCVImage with an empty image path.
         */
        GCVImage()
        : imgPath("") { }
        
        /**
         *  Constructor.
         *
         *  @param filepath Path to the image file.
         *  @param name A name describing the image.
         *
         *  @return A new GCVImage with the given image path.
         */
        GCVImage(string filepath, string name = "")
        : imgPath(filepath) {
        
            if (name == "") {
                name = filepath;
            }
        }
        
        
        /**
         *  Path to the image file.
         */
        string imgPath;
        
        /**
         *  Allows for matrix retrieval only when needed.
         *
         *  @return The Mat at the GCVImage's path.
         */
        Mat loadMat();
        
        /**
         *  Displays the image until key-press.
         */
        void show();
    };
}

#endif /* gcvImage_hpp */
