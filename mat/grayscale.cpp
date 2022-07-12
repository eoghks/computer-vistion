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
//			
//			int b = image.at<Vec3b>(y, x)[0];
//			int g = image.at<Vec3b>(y, x)[1];
//			int r = image.at<Vec3b>(y, x)[2];
//
//			int gray = (b + g + r) / 3;
//
//			result_image.at<Vec3b>(y, x)[0] = gray;
//			result_image.at<Vec3b>(y, x)[1] = gray;
//			result_image.at<Vec3b>(y, x)[2] = gray;
//			
//		}
//	}
//
//	imshow("Original", image);
//	imshow("result", result_image);
//	waitKey(0);
//
//	return 0;
//}
