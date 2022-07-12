#include <algorithm>
#include "moravec.hpp"
#include<iostream>
using namespace std;

transformations::Moravec::Moravec(cv::InputArray& original_image)
{
	cv::Mat src = original_image.getMat();
	confidence_map.create(src.size(), CV_32FC1);

	// 외곽 2개 픽셀의 Confidence는 0으로 가정
	for (int w = 0; w < src.cols; ++w)
	{
		confidence_map.at<float>(0, w) = 0.0;
		confidence_map.at<float>(1, w) = 0.0;
		confidence_map.at<float>(src.rows - 1, w) = 0.0;
		confidence_map.at<float>(src.rows - 2, w) = 0.0;
	}

	for (int h = 0; h < src.rows; ++h)
	{
		confidence_map.at<float>(h, 0) = 0.0;
		confidence_map.at<float>(h, 1) = 0.0;
		confidence_map.at<float>(h, src.cols - 1) = 0.0;
		confidence_map.at<float>(h, src.cols - 2) = 0.0;
	}
}


void transformations::Moravec::FindConfidenceMap(cv::InputArray& original_image)
{
	cv::Mat src = original_image.getMat();

	/**
	 * src를 이용하여 모라벡 알고리즘의 Confidence를 계산한 뒤
	 * 이를 confidence_map에 저장하세요.
	 * (confidence_map은 클래스 멤버 변수로 선언되어 있습니다.)
	 */
	// ** 지금부터 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
	for (int w = 2; w < src.rows - 2; w++) {
		for (int h = 2; h < src.cols - 2; h++) {

			int u = (((unsigned int)src.at<uchar>(w - 1, h - 2) - (unsigned int)src.at<uchar>(w - 1, h - 1)) *
				((unsigned int)src.at<uchar>(w - 1, h - 2) - (unsigned int)src.at<uchar>(w - 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w - 1, h - 1) - (unsigned int)src.at<uchar>(w - 1, h)) *
					((unsigned int)src.at<uchar>(w - 1, h - 1) - (unsigned int)src.at<uchar>(w - 1, h))) +
				(((unsigned int)src.at<uchar>(w - 1, h) - (unsigned int)src.at<uchar>(w - 1, h + 1)) *
					((unsigned int)src.at<uchar>(w - 1, h) - (unsigned int)src.at<uchar>(w - 1, h + 1))) +
				(((unsigned int)src.at<uchar>(w, h - 2) - (unsigned int)src.at<uchar>(w, h - 1)) *
					((unsigned int)src.at<uchar>(w, h - 2) - (unsigned int)src.at<uchar>(w, h - 1))) +
				(((unsigned int)src.at<uchar>(w, h - 1) - (unsigned int)src.at<uchar>(w, h)) *
					((unsigned int)src.at<uchar>(w, h - 1) - (unsigned int)src.at<uchar>(w, h))) +
				(((unsigned int)src.at<uchar>(w, h) - (unsigned int)src.at<uchar>(w, h + 1)) *
					((unsigned int)src.at<uchar>(w, h) - (unsigned int)src.at<uchar>(w, h + 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h - 2) - (unsigned int)src.at<uchar>(w + 1, h - 1)) *
					((unsigned int)src.at<uchar>(w + 1, h - 2) - (unsigned int)src.at<uchar>(w + 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h - 1) - (unsigned int)src.at<uchar>(w + 1, h)) *
					((unsigned int)src.at<uchar>(w + 1, h - 1) - (unsigned int)src.at<uchar>(w + 1, h))) +
				(((unsigned int)src.at<uchar>(w + 1, h) - (unsigned int)src.at<uchar>(w + 1, h + 1)) *
					((unsigned int)src.at<uchar>(w + 1, h) - (unsigned int)src.at<uchar>(w + 1, h + 1)));

			int b = (((unsigned int)src.at<uchar>(w - 1, h ) - (unsigned int)src.at<uchar>(w - 1, h - 1)) *
				((unsigned int)src.at<uchar>(w - 1, h ) - (unsigned int)src.at<uchar>(w - 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w - 1, h + 1) - (unsigned int)src.at<uchar>(w - 1, h)) *
					((unsigned int)src.at<uchar>(w - 1, h + 1) - (unsigned int)src.at<uchar>(w - 1, h))) +
				(((unsigned int)src.at<uchar>(w - 1, h + 2) - (unsigned int)src.at<uchar>(w - 1, h + 1)) *
					((unsigned int)src.at<uchar>(w - 1, h + 2) - (unsigned int)src.at<uchar>(w - 1, h + 1))) +
				(((unsigned int)src.at<uchar>(w, h ) - (unsigned int)src.at<uchar>(w, h - 1)) *
					((unsigned int)src.at<uchar>(w, h ) - (unsigned int)src.at<uchar>(w, h - 1))) +
				(((unsigned int)src.at<uchar>(w, h + 1) - (unsigned int)src.at<uchar>(w, h)) *
					((unsigned int)src.at<uchar>(w, h + 1) - (unsigned int)src.at<uchar>(w, h))) +
				(((unsigned int)src.at<uchar>(w, h + 2) - (unsigned int)src.at<uchar>(w, h + 1)) *
					((unsigned int)src.at<uchar>(w, h + 2) - (unsigned int)src.at<uchar>(w, h + 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h ) - (unsigned int)src.at<uchar>(w + 1, h - 1)) *
					((unsigned int)src.at<uchar>(w + 1, h ) - (unsigned int)src.at<uchar>(w + 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h + 1) - (unsigned int)src.at<uchar>(w + 1, h)) *
					((unsigned int)src.at<uchar>(w + 1, h + 1) - (unsigned int)src.at<uchar>(w + 1, h))) +
				(((unsigned int)src.at<uchar>(w + 1, h + 2) - (unsigned int)src.at<uchar>(w + 1, h + 1)) *
					((unsigned int)src.at<uchar>(w + 1, h + 2) - (unsigned int)src.at<uchar>(w + 1, h + 1)));

			int r = (((unsigned int)src.at<uchar>(w , h - 1) - (unsigned int)src.at<uchar>(w - 1, h - 1)) *
				((unsigned int)src.at<uchar>(w , h - 1) - (unsigned int)src.at<uchar>(w - 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w , h ) - (unsigned int)src.at<uchar>(w - 1, h)) *
					((unsigned int)src.at<uchar>(w , h ) - (unsigned int)src.at<uchar>(w - 1, h))) +
				(((unsigned int)src.at<uchar>(w , h + 1) - (unsigned int)src.at<uchar>(w - 1, h + 1)) *
					((unsigned int)src.at<uchar>(w , h + 1) - (unsigned int)src.at<uchar>(w - 1, h + 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h - 1) - (unsigned int)src.at<uchar>(w, h - 1)) *
					((unsigned int)src.at<uchar>(w + 1, h - 1) - (unsigned int)src.at<uchar>(w, h - 1))) +
				(((unsigned int)src.at<uchar>(w + 1, h ) - (unsigned int)src.at<uchar>(w, h)) *
					((unsigned int)src.at<uchar>(w +1, h ) - (unsigned int)src.at<uchar>(w, h))) +
				(((unsigned int)src.at<uchar>(w +1, h + 1) - (unsigned int)src.at<uchar>(w, h + 1)) *
					((unsigned int)src.at<uchar>(w +1, h + 1) - (unsigned int)src.at<uchar>(w, h + 1))) +
				(((unsigned int)src.at<uchar>(w + 2, h - 1) - (unsigned int)src.at<uchar>(w + 1, h - 1)) *
					((unsigned int)src.at<uchar>(w +2, h - 1) - (unsigned int)src.at<uchar>(w + 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w + 2, h ) - (unsigned int)src.at<uchar>(w + 1, h)) *
					((unsigned int)src.at<uchar>(w + 2, h ) - (unsigned int)src.at<uchar>(w + 1, h))) +
				(((unsigned int)src.at<uchar>(w + 2, h + 1) - (unsigned int)src.at<uchar>(w + 1, h + 1)) *
					((unsigned int)src.at<uchar>(w + 2, h + 1) - (unsigned int)src.at<uchar>(w + 1, h + 1)));

			int l = (((unsigned int)src.at<uchar>(w - 2 , h - 1) - (unsigned int)src.at<uchar>(w - 1, h - 1)) *
				((unsigned int)src.at<uchar>(w - 2, h - 1) - (unsigned int)src.at<uchar>(w - 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w - 2 , h) - (unsigned int)src.at<uchar>(w - 1, h)) *
					((unsigned int)src.at<uchar>(w - 2, h) - (unsigned int)src.at<uchar>(w - 1, h))) +
				(((unsigned int)src.at<uchar>(w -2, h + 1) - (unsigned int)src.at<uchar>(w - 1, h + 1)) *
					((unsigned int)src.at<uchar>(w-2, h + 1) - (unsigned int)src.at<uchar>(w - 1, h + 1))) +
				(((unsigned int)src.at<uchar>(w - 1, h - 1) - (unsigned int)src.at<uchar>(w, h - 1)) *
					((unsigned int)src.at<uchar>(w - 1, h - 1) - (unsigned int)src.at<uchar>(w, h - 1))) +
				(((unsigned int)src.at<uchar>(w - 1, h) - (unsigned int)src.at<uchar>(w, h)) *
					((unsigned int)src.at<uchar>(w - 1, h) - (unsigned int)src.at<uchar>(w, h))) +
				(((unsigned int)src.at<uchar>(w - 1, h + 1) - (unsigned int)src.at<uchar>(w, h + 1)) *
					((unsigned int)src.at<uchar>(w - 1, h + 1) - (unsigned int)src.at<uchar>(w, h + 1))) +
				(((unsigned int)src.at<uchar>(w , h - 1) - (unsigned int)src.at<uchar>(w + 1, h - 1)) *
					((unsigned int)src.at<uchar>(w , h - 1) - (unsigned int)src.at<uchar>(w + 1, h - 1))) +
				(((unsigned int)src.at<uchar>(w , h) - (unsigned int)src.at<uchar>(w + 1, h)) *
					((unsigned int)src.at<uchar>(w , h) - (unsigned int)src.at<uchar>(w + 1, h))) +
				(((unsigned int)src.at<uchar>(w , h + 1) - (unsigned int)src.at<uchar>(w + 1, h + 1)) *
					((unsigned int)src.at<uchar>(w , h + 1) - (unsigned int)src.at<uchar>(w + 1, h + 1)));

			
			float confidence = min({ u, l, b, r });
			

			confidence_map.at<float>(w, h) = confidence;
		}
	}


	// ** 여기까지 코드를 작성하세요. 이 줄은 지우시면 안 됩니다 **
}



void transformations::Moravec::DrawFeature(cv::OutputArray& result_image)
{
	cv::Mat dst = result_image.getMat();

	for (int h = 0; h < confidence_map.rows; ++h)
	{
		for (int w = 0; w < confidence_map.cols; ++w)
		{
			if (confidence_map.at<float>(h, w) >= 15000)
			{
				cv::circle(dst, cv::Point(w, h), 3, cv::Scalar(255, 0, 0));
			}
		}
	}
}