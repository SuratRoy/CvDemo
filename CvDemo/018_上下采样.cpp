#include <opencv2/opencv.hpp>
using namespace cv;

int main018() {
	Mat src = imread("Pictures\\5.jpg");
	imshow("src", src);

	Mat dst_up, dst_down;

	//上采样，图像放大，宽高变为源图2倍
	pyrUp(src, dst_up);
	imshow("dst_up", dst_up);

	//下采样，图像缩小，宽高变为源图二分之一
	pyrDown(src, dst_down);
	imshow("dst_down", dst_down);

	waitKey(0);
	return 0;
}