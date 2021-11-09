/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 2 of the cookbook:
Computer Vision Programming using the OpenCV Library.
by Robert Laganiere, Packt Publishing, 2011.

This program is free software; permission is hereby granted to use, copy, modify,
and distribute this source code, or portions thereof, for any purpose, without fee,
subject to the restriction that the copyright notice may not be removed
or altered from any source or altered source distribution.
The software is released on an as-is basis and without any warranties of any kind.
In particular, the software is not guaranteed to be fault-tolerant or free from failure.
The author disclaims all warranties with regard to this software, any use,
and any consequent failure, is purely the responsibility of the user.

Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

void sharpen(const Mat &image, Mat &result) {

	result.create(image.size(), image.type()); // allocate if necessary

	for (int j = 1; j<image.rows - 1; j++) { // for all rows (except first and last)

		const uchar* previous = image.ptr<const uchar>(j - 1); // previous row
		const uchar* current = image.ptr<const uchar>(j);	// current row
		const uchar* next = image.ptr<const uchar>(j + 1);		// next row

		uchar* output = result.ptr<uchar>(j);	// output row

		for (int i = 1; i<image.cols - 1; i++) {

			*output++ = cv::saturate_cast<uchar>(4 * current[i] - current[i - 1] - current[i + 1] - previous[i] - next[i]);
			//			output[i]= cv::saturate_cast<uchar>(5*current[i]-current[i-1]-current[i+1]-previous[i]-next[i]); 
		}
	}

	// Set the unprocess pixels to 0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}

int main()
{
	Mat image = imread("lena.jpg", 0);
	if (!image.data)
		return 0;

	Mat result;
	result.create(image.size(), image.type());

	sharpen(image, result);
	
	namedWindow("Image");
	imshow("Image", result);

	waitKey();

	return 0;
}


