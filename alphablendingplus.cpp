#include <png++/png.hpp>
#include <png++/image.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <png++/rgba_pixel.hpp>
#include <png++/rgb_pixel.hpp>
using namespace png;
 
int main(int nNumberofArgs, char *pszArgs[]) {

  const char *filename;
  filename=pszArgs[1];
  png::image< png::rgb_pixel > image(filename);
  png::image< png::rgb_pixel > image1(image.get_width()/2,image.get_height()/2);
  std::cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  std::cout<<"lungimea imagini: "<<image.get_width()<<"\n";

	for (size_t y = 0; y < image.get_height(); ++y) {
	    for (size_t x = 0; x < image.get_width(); ++x) {
		rgb_pixel pixel=image.get_pixel(x,y);
		image1.set_pixel(x/2,y/2,pixel);
		}
	  }

	  for (size_t y = 0; y < image1.get_height(); ++y) {
	    for (size_t x = 0; x < image1.get_width(); ++x) {
		image[y][x].red = (1-0.5)*image1.get_pixel(x,y).red+0.5*image.get_pixel(x,y).red;
		image[y][x].green = (1-0.5)*image1.get_pixel(x,y).green+0.5*image.get_pixel(x,y).green;
		image[y][x].blue = /*0;*/(1-0.5)*image1.get_pixel(x,y).blue+0.5*image.get_pixel(x,y).blue;
		//image2[y][x].alpha = image1.get_pixel(x,y).red;
		}
	  }
    
 image.write(filename);
 //image1.write("minuscul.png");
}
