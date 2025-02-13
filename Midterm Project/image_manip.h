#ifndef IMAGE_MANIP_H
#define IMAGE_MANIP_H

#include "ppm_io.h"

// store PI as a constant
#define PI 3.14159265358979323846

// macro to square a number
#define sq(X) ((X) * (X))

//////////////////////////////////
// Image manipulation functions //
//////////////////////////////////

//______grayscale______
/* convert an image to grayscale (NOTE: pixels are still
* RGB, but the three values will be equal)
*/
Image grayscale( const Image in );

/* _______alpha blend________
* blend two images into one using the given alpha factor
*/
Image blend( const Image in1, const Image in2 , double alpha );

/* _______rotate-ccw________
* rotate the input image counter-clockwise
*/
Image rotate_ccw( const Image in );

/* _______pointilism________
* apply a painting like effect i.e. poitilism technique.
*/
Image pointilism( const Image in , unsigned int seed );

//______blur______
/* apply a blurring filter to the image
*/
Image blur( const Image in , double sigma );

/* create a gaussian matrix to fiter the image for the blur
 */
double ** gaussian_matrix(int N, double sigma);

/* blur a given pixel using a given gaussian matrix
 */
Pixel filter_pixel(const int i, const int j, const Image in, const int N, double ** gauss);

//______saturate______
/* Saturate the image by scaling the deviation from gray
*/
Image saturate( const Image in , double scale );

#endif
