#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void vilagosit(Mat img)
{
	img = img + 100;
}


int main()
{
	cv::Mat img = cv::imread("tiger.jpg", ImreadModes::IMREAD_GRAYSCALE);
	
	vilagosit(img);
	
	cv::Mat dst;

	cv::imshow("proba", img);

	std::cout << "Sorok:" << img.rows << std::endl;
	std::cout << "Oszlopok:" << img.cols << std::endl;
	std::cout << "Channels: " << img.channels() << std::endl;
	std::cout << "Type: " << img.type() << std::endl;
	std::cout << "IsEmpty: " << img.empty() << std::endl;

	cv::Mat b = Mat::zeros(img.size(), CV_8UC1);
	b.setTo(0);
	cv::imshow("szurke", b);
	cv::waitKey();

	return 0;
}
