//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat result_image;
//	Mat image = imread("lena512.bmp", IMREAD_COLOR);
//	image.copyTo(result_image);
//
//	for (int y = 0; y < image.rows; y++) {
//		for (int x = 0; x < image.cols; x++) {
//			//int a = image.at<uchar>(y, x);
//			result_image.at<Vec3b>(y, x)[0] = 255 - image.at<Vec3b>(y, x)[0];
//			result_image.at<Vec3b>(y, x)[1] = 255 - image.at<Vec3b>(y, x)[1];
//			result_image.at<Vec3b>(y, x)[2] = 255 - image.at<Vec3b>(y, x)[2];
//			//result_image.at<uchar>(y, x) = 255 - a;
//		}
//	}
//
//	imshow("Original", image);
//	imshow("result", result_image);
//	waitKey(0);
//
//	return 0;
//}
