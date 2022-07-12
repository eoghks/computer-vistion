#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat result_image;
	Mat image = imread("lena512.bmp", IMREAD_COLOR);
	image.copyTo(result_image);

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			
			int b = image.at<Vec3b>(y, x)[0]+50;
			int g = image.at<Vec3b>(y, x)[1]+50;
			int r = image.at<Vec3b>(y, x)[2]+50;

			result_image.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(b);
			result_image.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(g);
			result_image.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(r);
			
		}
	}

	imshow("Original", image);
	imshow("result", result_image);
	waitKey(0);

	return 0;
}
