// The Purpose of this code is to take the vector of pixels and write it out into an image file

// Inputs: 
// pixels - 1D vector of the pixels
// Outputs:
// image file


#include<iostream>
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

int main()
{
return 0;
}
