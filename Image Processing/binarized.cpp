//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat result_image;
//	Mat image = imread("lena512.bmp", IMREAD_GRAYSCALE);
//	image.copyTo(result_image);
//
//	
//	for (int y = 0; y < image.rows; y++) {
//		for (int x = 0; x < image.cols; x++) {
//
//			int b = (unsigned int) image.at<uchar>(y, x) ;
//
//			if(b<128)
//				result_image.at<uchar>(y, x) = 0;
//			else
//				result_image.at<uchar>(y, x) = 255;
//		
//			
//
//		}
//	}
//
//	imshow("Original", image);
//	imshow("result", result_image);
//	waitKey(0);
//
//	imwrite("lenna_binarized.jpg", result_image);
//
//	return 0;
//}
