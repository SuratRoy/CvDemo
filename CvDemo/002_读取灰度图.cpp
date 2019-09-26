#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main002() {
	//加载灰度图
	Mat src = imread("Pictures\\1.png", cv::ImreadModes::IMREAD_GRAYSCALE);
	imshow("img", src);
	waitKey(0);

	return 0;
}