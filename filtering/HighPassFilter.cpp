#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat result_image;
	Mat image = imread("lenna.bmp", IMREAD_GRAYSCALE);
	image.copyTo(result_image);
	
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			//일반적인 경우
			if (y != 0 && y != image.rows - 1 && x != 0 && x != image.cols - 1) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y, x - 1);
				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
				int p4 = (unsigned int)image.at<uchar>(y + 1, x);
				int p5 = (unsigned int)image.at<uchar>(y + 1, x - 1);
				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
				int p7 = (unsigned int)image.at<uchar>(y - 1, x);
				int p8 = (unsigned int)image.at<uchar>(y - 1, x - 1);
				int p9 = (unsigned int)image.at<uchar>(y - 1, x + 1);
				int result= (int)(8 * p1 - p2 - p3 - p4 - p5 - p6 - p7 - p8 - p9);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);
			}
			//각꼭지점 
			else if (y == 0 && x == 0) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y + 1, x);
				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
				int p4 = (unsigned int)image.at<uchar>(y + 1, x + 1);
				int result = (int)(3 * p1 - p2 - p3 - p4);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);
			}
			else if (y == 0 && x == image.cols - 1) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y + 1, x);
				int p3 = (unsigned int)image.at<uchar>(y, x - 1);
				int p4 = (unsigned int)image.at<uchar>(y + 1, x - 1);
				int result = (int)(3 * p1 - p2 - p3 - p4);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);

			}

			else if (y == image.rows - 1 && x == image.cols - 1) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
				int p3 = (unsigned int)image.at<uchar>(y, x - 1);
				int p4 = (unsigned int)image.at<uchar>(y - 1, x - 1);
				int result = (int)(3 * p1 - p2 - p3 - p4);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);

			}

			else if (y == image.rows - 1 && x == 0) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
				int p4 = (unsigned int)image.at<uchar>(y - 1, x + 1);
				int result = (int)(3 * p1 - p2 - p3 - p4);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);

			}

			//x,y한면만 0인경우
			else if (y == 0) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y, x - 1);
				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
				int p4 = (unsigned int)image.at<uchar>(y + 1, x);
				int p5 = (unsigned int)image.at<uchar>(y + 1, x - 1);
				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
				int result = (int)(5 * p1 - p2 - p3 - p4 - p5 - p6);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);

			}

			else if (x == 0) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
				int p3 = (unsigned int)image.at<uchar>(y + 1, x);
				int p4 = (unsigned int)image.at<uchar>(y, x + 1);
				int p5 = (unsigned int)image.at<uchar>(y - 1, x + 1);
				int p6 = (unsigned int)image.at<uchar>(y + 1, x + 1);
				int result = (int)(5 * p1 - p2 - p3 - p4 - p5 - p6);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);

			}

			//x나 y가 각끝인경우
			else if (y == image.rows - 1) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y, x - 1);
				int p3 = (unsigned int)image.at<uchar>(y, x + 1);
				int p4 = (unsigned int)image.at<uchar>(y - 1, x);
				int p5 = (unsigned int)image.at<uchar>(y - 1, x - 1);
				int p6 = (unsigned int)image.at<uchar>(y - 1, x + 1);
				int result = (int)(5 * p1 - p2 - p3 - p4 - p5 - p6);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);
			}

			else if (x == image.cols - 1) {
				int p1 = (unsigned int)image.at<uchar>(y, x);
				int p2 = (unsigned int)image.at<uchar>(y - 1, x);
				int p3 = (unsigned int)image.at<uchar>(y + 1, x);
				int p4 = (unsigned int)image.at<uchar>(y, x - 1);
				int p5 = (unsigned int)image.at<uchar>(y - 1, x - 1);
				int p6 = (unsigned int)image.at<uchar>(y + 1, x - 1);
				int result = (int)(5 * p1 - p2 - p3 - p4 - p5 - p6);
				result_image.at<uchar>(y, x) = saturate_cast<uchar>(result);
				

			}

		}
	}

	imshow("Original", image);
	imshow("result", result_image);
	waitKey(0);

	imwrite("lenna_hpf.bmp", result_image);

	return 0;
}
