#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "GCVImage.hpp"

using namespace gcv;
using namespace cv;

TEST_CASE( "GCVImage initialization" ) {
    REQUIRE( imread("./test-image.png").data != NULL );
    GCVImage *image1 = new GCVImage("./test-image.png", "octocat", false);

    REQUIRE( image1->name == "octocat" );
    REQUIRE( image1->imgPath == "./test-image.png" );
    REQUIRE( image1->matrixIsLoaded() == false );

    GCVImage *image2 = new GCVImage("./test-image.png", "", true);
    REQUIRE( image2->matrixIsLoaded() == true );
    REQUIRE( image2->name == "./test-image.png" );
}

TEST_CASE( "GCVImage matrix loading" ) {
    REQUIRE( imread("./test-image.png").data != NULL );
    GCVImage *image1 = new GCVImage("./test-image.png", "octocat", false);

    REQUIRE( image1->name == "octocat" );
    REQUIRE( image1->imgPath == "./test-image.png" );
    REQUIRE( image1->matrixIsLoaded() == false );
    image1->loadMat(false);
    REQUIRE( image1->matrixIsLoaded() == false );
    image1->loadMat(true);
    REQUIRE( image1->matrixIsLoaded() == true );
}
