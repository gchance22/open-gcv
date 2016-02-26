#include "catch.hpp"
#include "gcv_utilities.hpp"

using namespace gcv;
using namespace cv;


// not very strong tests because there is only one image.
TEST_CASE( "Number of images in directory" ) {
    REQUIRE( numImagesInDirectory(".") == 1 );
}

TEST_CASE( "Image names in directory" ) {
    vector<string> names = imageNamesInDirectory(".");
    REQUIRE( names.size() == 1 );
    REQUIRE( names[0] == "test-image.png" );
}
TEST_CASE( "Loading images from directory" ) {
    vector<GCVImage> images = loadImagesFromDirectory(".", false, false);
    REQUIRE( images.size() == 1 );
}
