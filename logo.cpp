

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	// read images
	cv::Mat image = cv::imread("boldt.jpg");
	cv::Mat logo = cv::imread("logo.bmp");

	// define image ROI
	cv::Mat imageROI;
	imageROI = image(cv::Rect(385, 270, logo.cols, logo.rows));

	// add logo to image 
	cv::addWeighted(imageROI, 1.0, logo, 0.3, 0., imageROI);

	// show result
	cv::namedWindow("with logo");
	cv::imshow("with logo", image);

	
	cv::waitKey();

	return 0;
}
