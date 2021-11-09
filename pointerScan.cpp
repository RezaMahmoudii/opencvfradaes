#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	//reading and showing an image
	Mat im(256, 256, CV_8UC3);
	int nl = im.rows; // number of lines
	int nc = im.cols * im.channels(); // total number of elements per line

	for (int j = 0; j<nl; j++) {

		uchar* data = im.ptr<uchar>(j);

		for (int i = 0; i < nc; i=i+3){
			
			// process each pixel ---------------------
			if (i/3 < 80 && j < 80){
			//	data[i] = 0;
			//*(data + i) = 0;
			  *(data++) = 0;

			//data[i + 1] = 0;
			//*(data + i+1) = 0;
			  *(data++) = 0;

			//data[i + 2] = 255;
			//*(data + i+2) = 255;
			  *(data++) = 255;
		    }
			else if (i/3 < 160 && j<160){
				//data[i] = 0;
				*(data++) = 0;

				//data[i + 1] = 255;
				*(data++) = 255;

				//data[i + 2] = 0;
				*(data++) = 0;
			}

			else {
				//data[i] = 255;
				*(data++) = 255;

				//data[i + 1] = 0;
				*(data++) = 0;

				//data[i + 2] = 0;
				*(data++) = 0;
			}
			

			

		}    // end of pixel processing ----------------    
		
	}// end of line 
	
	namedWindow("image");
	imshow("image", im);
	waitKey(0);
}
