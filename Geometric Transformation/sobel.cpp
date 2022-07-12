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
//	// SobelFilterY의 CreateMask()를 구현하세요.
//	SobelFilterY sobelYFilter;
//	sobelYFilter.CreateMask();
//	sobelYFilter.Convolute(original_image, sobelYOut);
//
//	// SobelFilterX의 CreateMask()를 구현하세요.
//	SobelFilterX sobelXFilter;
//	sobelXFilter.CreateMask();
//	sobelXFilter.Convolute(original_image, sobelXOut);
//
//	cv::Mat edgeStrength;
//	edgeStrength.create(original_image.size(), CV_8UC1);
//
//	/**
//	 * sobelYOut과 sobelXOut을 이용하여 Edge Strength Map을 구하세요.
//	 */
//	 // ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
//	for (int i = 1; i < original_image.rows - 1; i++) {
//		for (int j = 1; j < original_image.cols - 1; j++) {
//			edgeStrength.at<uchar>(i, j) = sqrt(pow((int)sobelYOut.at<float>(i, j), 2) + pow((int)sobelXOut.at<float>(i, j), 2));
//		}
//	}
//	// ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
//
//	cv::imshow("sobelY-Output", sobelYOut);
//	cv::imshow("sobelX-Output", sobelXOut);
//	cv::imshow("Edge Strength", edgeStrength);
//	cv::waitKey();
//
//	// 이미지를 파일로 저장한다.
//	cv::imwrite("tibetfox_y.bmp", sobelYOut);
//	cv::imwrite("tibetfox_x.bmp", sobelXOut);
//	cv::imwrite("tibetfox_strength.bmp", edgeStrength);
//	std::cout << "파일 저장 완료!" << std::endl;
//}