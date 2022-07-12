//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat result_image;
//	Mat image = imread("salt_pepper.bmp", IMREAD_GRAYSCALE);
//	image.copyTo(result_image);
//	
//	for (int y = 0; y < image.rows; y++) {
//		for (int x = 0; x < image.cols; x++) {
//			//일반적인 경우
//			if (y != 0 && y != image.rows - 1 && x != 0 && x != image.cols - 1) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y, x - 1);
//				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
//				int p4 = (unsigned int)image.at<uchar>(y + 1, x);
//				int p5 = (unsigned int)image.at<uchar>(y + 1, x - 1);
//				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
//				int p7 = (unsigned int)image.at<uchar>(y - 1, x);
//				int p8 = (unsigned int)image.at<uchar>(y - 1, x - 1);
//				int p9 = (unsigned int)image.at<uchar>(y - 1, x + 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4 + p5+ p6+p7+p8+p9)/9);
//			}
//			//각꼭지점 
//			else if (y ==0 && x == 0) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y+1, x);
//				int p3 = (unsigned int)image.at<uchar>(y, x+1);
//				int p4 = (unsigned int)image.at<uchar>(y+1, x+1);
//				result_image.at<uchar>(y, x) = (int)((p1+p2+p3+p4)/4);
//			}
//			else if (y == 0 && x == image.cols - 1) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y + 1, x);
//				int p3 = (unsigned int)image.at<uchar>(y, x - 1);
//				int p4 = (unsigned int)image.at<uchar>(y + 1, x - 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4)/4);
//				
//			}
//
//			else if (y == image.rows-1 && x == image.cols - 1) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
//				int p3 = (unsigned int)image.at<uchar>(y, x - 1);
//				int p4 = (unsigned int)image.at<uchar>(y - 1, x - 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4)/4);
//
//			}
//
//			else if (y == image.rows - 1 && x == 0) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
//				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
//				int p4 = (unsigned int)image.at<uchar>(y - 1, x + 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4)/4);
//
//			}
//
//			//x,y한면만 0인경우
//			else if (y == 0) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y , x-1);
//				int p3 = (unsigned int)image.at<uchar>(y,  x+1);
//				int p4 = (unsigned int)image.at<uchar>(y + 1, x);
//				int p5 = (unsigned int)image.at<uchar>(y + 1, x - 1);
//				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4 +p5+ p6)/6);
//
//			}
//
//			else if (x == 0) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y-1, x );
//				int p3 = (unsigned int)image.at<uchar>(y+1, x );
//				int p4 = (unsigned int)image.at<uchar>(y , x + 1);
//				int p5 = (unsigned int)image.at<uchar>(y - 1, x + 1);
//				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4 + p5+ p6)/6);
//
//			}
//
//			//x나 y가 각끝인경우
//			else if (y == image.rows - 1) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y, x - 1);
//				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
//				int p4 = (unsigned int)image.at<uchar>(y - 1, x);
//				int p5 = (unsigned int)image.at<uchar>(y - 1, x - 1);
//				int p6 = (unsigned int)image.at<uchar>(y - 1, x + 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4 + p5+ p6)/6);
//			}
//
//			else if (x == image.cols-1) {
//				int p1 = (unsigned int)image.at<uchar>(y, x);
//				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
//				int p3 = (unsigned int)image.at<uchar>(y + 1, x);
//				int p4 = (unsigned int)image.at<uchar>(y, x - 1);
//				int p5 = (unsigned int)image.at<uchar>(y - 1, x - 1);
//				int p6 = (unsigned int)image.at<uchar>(y + 1, x - 1);
//				result_image.at<uchar>(y, x) = (int)((p1 + p2 + p3 + p4 + p5+ p6)/6);
//
//			}
//
//		}
//	}
//
//	imshow("Original", image);
//	imshow("result", result_image);
//	waitKey(0);
//
//	imwrite("salt_pepper_lpf.bmp", result_image);
//
//	return 0;
//}
