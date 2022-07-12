//
//#include "opencv2/opencv.hpp"
//#include "filter.hpp"
//
//int main()
//{
//	cv::Mat original_image, sobelXOut, sobelYOut;
//	original_image = cv::imread("tibetfox.bmp", cv::IMREAD_GRAYSCALE);
//	sobelXOut.create(original_image.size(), CV_8UC1);
//	sobelYOut.create(original_image.size(), CV_8UC1);
//
//	imshow("original", original_image);
//
//	// SobelFilterY�� CreateMask()�� �����ϼ���.
//	SobelFilterY sobelYFilter;
//	sobelYFilter.CreateMask();
//	sobelYFilter.Convolute(original_image, sobelYOut);
//
//	// SobelFilterX�� CreateMask()�� �����ϼ���.
//	SobelFilterX sobelXFilter;
//	sobelXFilter.CreateMask();
//	sobelXFilter.Convolute(original_image, sobelXOut);
//
//	cv::Mat edgeStrength;
//	edgeStrength.create(original_image.size(), CV_8UC1);
//
//	/**
//	 * sobelYOut�� sobelXOut�� �̿��Ͽ� Edge Strength Map�� ���ϼ���.
//	 */
//	 // ** ���ݺ��� �ڵ带 �ۼ��ϼ���. �� ���� ����ø� �� �˴ϴ� **
//	for (int i = 1; i < original_image.rows - 1; i++) {
//		for (int j = 1; j < original_image.cols - 1; j++) {
//			edgeStrength.at<uchar>(i, j) = sqrt(pow((int)sobelYOut.at<float>(i, j), 2) + pow((int)sobelXOut.at<float>(i, j), 2));
//		}
//	}
//	// ** ������� �ڵ带 �ۼ��ϼ���. �� ���� ����ø� �� �˴ϴ� **
//
//	cv::imshow("sobelY-Output", sobelYOut);
//	cv::imshow("sobelX-Output", sobelXOut);
//	cv::imshow("Edge Strength", edgeStrength);
//	cv::waitKey();
//
//	// �̹����� ���Ϸ� �����Ѵ�.
//	cv::imwrite("tibetfox_y.bmp", sobelYOut);
//	cv::imwrite("tibetfox_x.bmp", sobelXOut);
//	cv::imwrite("tibetfox_strength.bmp", edgeStrength);
//	std::cout << "���� ���� �Ϸ�!" << std::endl;
//}