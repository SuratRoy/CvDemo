using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

int main017() {
	Mat src = imread("Pictures\\14.png");
	imshow("src", src);

	//转灰度图
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	//二值化
	Mat binary;
	threshold(gray, binary, 254, 255, cv::ThresholdTypes::THRESH_BINARY);
	imshow("binary", binary);

	//定义3*3的结构元素
	Mat k = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(3, 3));
	Mat dst;
	//做闭操作，去除干扰，得到目标图像
	morphologyEx(binary, dst, cv::MorphTypes::MORPH_CLOSE, k);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}