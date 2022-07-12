//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat dissolve_3, dissolve_7;
//	Mat image1 = imread("cat.bmp", IMREAD_COLOR);
//	Mat image2 = imread("tibetfox.bmp", IMREAD_COLOR);
//	
//	image1.copyTo(dissolve_3);
//	image1.copyTo(dissolve_7);
//
//
//	for (int y = 0; y < image1.rows; y++) {
//		for (int x = 0; x < image1.cols; x++) {
//
//			int b1 = image1.at<Vec3b>(y, x)[0] ;
//			int g1 = image1.at<Vec3b>(y, x)[1] ;
//			int r1 = image1.at<Vec3b>(y, x)[2] ;
//
//			int b2 = image2.at<Vec3b>(y, x)[0];
//			int g2 = image2.at<Vec3b>(y, x)[1];
//			int r2 = image2.at<Vec3b>(y, x)[2];
//
//			int b = (int)(0.3 * b1 + 0.7 * b2);
//			int g = (int)(0.3 * g1 + 0.7 * g2);
//			int r = (int)(0.3 * r1 + 0.7 * r2);
//
//			int b3 = (int)(0.7 * b1 + 0.3 * b2);
//			int g3 = (int)(0.7 * g1 + 0.3 * g2);
//			int r3 = (int)(0.7 * r1 + 0.3 * r2);
//
//			dissolve_3.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(b);
//			dissolve_3.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(g);
//			dissolve_3.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(r);
//
//			dissolve_7.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(b3);
//			dissolve_7.at<Vec3b>(y, x)[1] = saturate_cast<uchar>(g3);
//			dissolve_7.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(r3);
//		}
//	}
//
//	imwrite("dissolve_3.bmp", dissolve_3);
//	imwrite("dissolve_7.bmp", dissolve_7);
//
//	imshow("dissolve_3", dissolve_3);
//	imshow("dissolve_7", dissolve_7);
//	waitKey(0);
//
//	return 0;
//}
