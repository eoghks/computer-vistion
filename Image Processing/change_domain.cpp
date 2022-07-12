#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat result_image;
	Mat image = imread("lena512.bmp", IMREAD_COLOR);
	image.copyTo(result_image);
	
	//image.copyTo(result_image);

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {

			int b = image.at<Vec3b>(y, x)[0];
			int g = image.at<Vec3b>(y, x)[1];
			int r = image.at<Vec3b>(y, x)[2];

			int y2 = (unsigned int) (0 + 0.299 * r + 0.587 * g + 0.114 * b);
			int cb = (unsigned int) (128 + -0.169 * r + -0.331 * g + 0.500 * b);
			int cr = (unsigned int) (128 + 0.500 * r + -0.419 * g + -0.081 * b);

			result_image.at<Vec3b>(y, x)[0] = y2;
			result_image.at<Vec3b>(y, x)[1] = cr;
			result_image.at<Vec3b>(y, x)[2] = cb;

		}
	}

	imshow("Original", image);
	imshow("result", result_image);
	waitKey(0);

	return 0;
}
