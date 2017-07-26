//Main

#include<iostream>

int main()
{
  double center_x, center_y, length_x, length_y, min_x, min_y, pixel_size;
  double x, y;
  int pixel_count_x, pixel_count_y;
  int i_x, i_y, i;
  int * pixels;
 
  
  center_x = -0.75;
  center_y = 0.00;
  length_x = 2.75;
  length_y = 2.0;
  min_x = center_x -length_x/2.0;
  max_y = center_y + length_y/2.0;
  pixel_count_x = 8192;
  pixel_size = length_x/pixel_count_x;
  pixel_count_y = length_y/pixel_size;
    
  pixels = new int[pixel_count_x*pixel_count_y];
  

  for (i_x=0; i_x<pixel_count_x; i_x++){
      for (i_y=0; i_y<pixel_count_y; i_y++){

          x = min_x + pixel_size_x*i_x;
          y = max_y - pixel_size*i_y;

          i = i_y*pixel_count_x+i_x;
          pixels[i] = Mandelbrot(x,y);

      }
  }


}

int Mandelbrot(double x, double y){
    int iter, iter_max=1000;
    double radius_z, radius_max=2.0;

    while ((radius_x < radius_max) && (iter < iter_max)){


    }

}
