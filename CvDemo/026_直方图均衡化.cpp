#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("src_gray", gray);

	Mat dst;
	//图像均衡化是一种提高图像对比度的方法，拉伸图像灰度直方图
	equalizeHist(gray, dst);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}