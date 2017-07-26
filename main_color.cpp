//Main

#include<iostream>
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
int pixelWriteout(unsigned char * pixels, int width, int height, int numPixels)
{
	int maxColorValue = 255;
	std::ofstream f("test.pgm", std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
	// Writing out the header to the file
	f << "P5\n" << width << " " << height << "\n" << maxColorValue << "\n";	
	// Writing out the data to the file
	for (int i = 0; i<numPixels; i++)
	{
	    f << pixels[i];
	}
	f.close();
	return 0;
 }

int Color(double distance, double pixelSize)
{
        if (distance < 0.5*pixelSize)
                return (pow(distance/(.5*pixelSize),.3333333)*255);
        else
                return 255;
}

#pragma acc routine seq
int Mandelbrot(double x, double y, double pixel_size){
    int iter, iter_max=10000;
    double distance = 0.0,dz_x=0.0, dz_y=0.0, radius=0.0, z_x=0.0, z_y=0.0, radius_max=18.0;
    iter = 0;
    while ((radius < radius_max) && (iter < iter_max)){
        double z_x_temp = z_x;
        double z_y_temp =z_y;
        double dz_x_temp = dz_x;
        double dz_y_temp = dz_y;
        dz_x = 2*(z_x_temp*dz_x_temp - z_y_temp*dz_y_temp) + 1;
        dz_y = 2*(z_y_temp*dz_x_temp + z_x_temp*dz_y_temp);
        z_x = z_x_temp * z_x_temp - z_y_temp*z_y_temp+x;
        z_y = 2*z_x_temp*z_y_temp+y;
        radius = pow(z_x*z_x+z_y*z_y, 0.5);
        iter = iter + 1;
    }
    double mag_dz = pow(dz_x*dz_x + dz_y*dz_y, 0.5);
    //double mag_z =  pow(z_x*z_x + z_y*z_y, 0.5);
    //distance = 2*log(mag_z)*mag_z/mag_dz;
    distance = 2*log(radius)*radius/mag_dz;
    return Color(distance, pixel_size);
}

int main()
{
  double center_x, center_y, length_x, length_y, min_x, max_y, pixel_size;
  double x, y;
  int pixel_count_x, pixel_count_y;
  int i_x, i_y, i;
  unsigned char * pixels;
 
  
  center_x = -0.75;
  center_y = 0.00;
  length_x = 2.75;
  length_y = 2.0;
  min_x = center_x -length_x/2.0;
  max_y = center_y + length_y/2.0;
  pixel_count_x = 8192;
  pixel_size = length_x/pixel_count_x;
  pixel_count_y = length_y/pixel_size;
  pixels = new unsigned char[pixel_count_x*pixel_count_y];
  
 
#pragma acc parallel loop
for (i=0; i < pixel_count_x*pixel_count_y; i++)
{
	i_x = i % pixel_count_x;
	i_y = i/pixel_count_y; // Note: floor by default
	x = min_x + pixel_size*i_x;
        y = max_y - pixel_size*i_y;
	pixels[i] = Mandelbrot(x,y, pixel_size);
}

/*
  for (i_x=0; i_x<pixel_count_x; i_x++){
    for (i_y=0; i_y<pixel_count_y; i_y++){

          x = min_x + pixel_size*i_x;
          y = max_y - pixel_size*i_y;

          i = i_y*pixel_count_x+i_x;
          pixels[i] = Mandelbrot(x,y);

      }
  }
*/
  pixelWriteout(pixels, pixel_count_x, pixel_count_y, pixel_count_x*pixel_count_y);
}

