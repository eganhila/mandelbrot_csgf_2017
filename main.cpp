//Main

#include<iostream>

int main()
{
  double center_x, center_y, length_x, length_y, min_x, min_y, pixel_size;
  int pixel_count_x, pixel_count_y;
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
}
