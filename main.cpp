//Main

#include<iostream>
#include<math.h>
#include<fstream>

int pixelWriteout(int * pixels, int width, int height, int numPixels, int numRow)
{
	int maxColorValue = 255;
	std::ofstream f("test.pgm", std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
	// Writing out the header to the file
	f << "P5\n" << width << " " << height << "\n" << maxColorValue << "\n";	
	// Writing out the data to the file
	for (int i = 1; i<numPixels; i++)
	{
		if (pixels[i] % numRow == 0)
			f << pixels[i] << "\n";
		else	
			f << pixels[i] << " ";
	}
	f.close();
	return 0;
 }

int Mandelbrot(double x, double y){
    int iter, iter_max=1000;
    double radius=0.0, z_x=0.0, z_y=0.0, radius_max=2.0;

    while ((radius < radius_max) && (iter < iter_max)){

        z_x = x*x-y*y+x;
        z_y = 2*x*y+y;
        radius = pow(z_x*z_x+z_y*z_y, 0.5);

        iter = iter + 1;
    }

    if ( iter < iter_max){
        return 1;
    }
    else{
        return 0;
    }

}

int main()
{
  double center_x, center_y, length_x, length_y, min_x, max_y, pixel_size;
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

          x = min_x + pixel_size*i_x;
          y = max_y - pixel_size*i_y;

          i = i_y*pixel_count_x+i_x;
          pixels[i] = Mandelbrot(x,y);

      }
  }

  pixelWriteout(pixels, pixel_count_x, pixel_count_y, pixel_count_x*pixel_count_y, pixel_count_y);


}

