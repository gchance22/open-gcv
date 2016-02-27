#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define TEST_IMAGE_PATH "./data/test-image.png"

#include "catch.hpp"
#include "GCVImage.hpp"

using namespace gcv;
using namespace cv;

TEST_CASE( "GCVImage initialization" ) {
    REQUIRE( imread(TEST_IMAGE_PATH).data != NULL );
    GCVImage *image1 = new GCVImage(TEST_IMAGE_PATH, "octocat", false);

    REQUIRE( image1->name == "octocat" );
    REQUIRE( image1->getPath() == TEST_IMAGE_PATH );
    REQUIRE( image1->matrixIsLoaded() == false );

    GCVImage *image2 = new GCVImage(TEST_IMAGE_PATH, "", true);
    REQUIRE( image2->matrixIsLoaded() == true );
    REQUIRE( image2->name == TEST_IMAGE_PATH );
}

TEST_CASE( "GCVImage matrix loading" ) {
    REQUIRE( imread(TEST_IMAGE_PATH).data != NULL );
    GCVImage *image1 = new GCVImage(TEST_IMAGE_PATH, "octocat", false);

    REQUIRE( image1->name == "octocat" );
    REQUIRE( image1->getPath() == TEST_IMAGE_PATH );
    REQUIRE( image1->matrixIsLoaded() == false );
    image1->getMat(false);
    REQUIRE( image1->matrixIsLoaded() == false );
    image1->getMat(true);
    REQUIRE( image1->matrixIsLoaded() == true );
}
