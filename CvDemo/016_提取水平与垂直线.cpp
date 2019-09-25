#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

int main016() {
	Mat src = imread("Pictures\\13.png");

	imshow("src", src);

	//二值化需要先将彩色图转为灰度图
	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	Mat dst_binary;
	//二值化操作，阈值为254，THRESH_BINARY_INV与CV_THRESH_BINARY相反
	////THRESH_BINARY_INV代表： value = value > 254 ? 0 : 255
	//所以白色（255）变为黑色（0），其他都变为白色（255）
	threshold(src, dst_binary, 254, 255, THRESH_BINARY_INV);
	imshow("dst_binary", dst_binary);

	//提取水平与垂直直线
	Mat dst_horizontal_line, dst_vertical_line;

	//定义水平结构元素
	Mat horizontal_kernel = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(dst_binary.cols / 8, 1));
	//用水平结构元素对二值图进行开操作，提取到目标图像
	morphologyEx(dst_binary, dst_horizontal_line, cv::MorphTypes::MORPH_OPEN, horizontal_kernel);
	imshow("dst_horizontal_line", dst_horizontal_line);

	//定义垂直结构元素
	Mat vertical_kernel = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(1, dst_binary.rows / 8));
	//用垂直结构元素对二值图进行开操作，提取到目标图像
	morphologyEx(dst_binary, dst_vertical_line, cv::MorphTypes::MORPH_OPEN, vertical_kernel);
	imshow("dst_vertical_line", dst_vertical_line);

	waitKey(0);
	return 0;
}