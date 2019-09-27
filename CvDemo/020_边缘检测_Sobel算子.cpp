#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//高斯滤波消除噪点
	GaussianBlur(src, src, Size(3, 3), 0);

	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	//利用Sobel算子求X,Y方向的梯度
	Mat dst_x_gradient, dst_y_gradient, dst_xy_gradient;
	//求X方向梯度
	Sobel(dst_gray, dst_x_gradient, CV_16S, 1, 0);
	//求Y方向梯度
	Sobel(dst_gray, dst_y_gradient, CV_16S, 0, 1);
	//取绝对值
	convertScaleAbs(dst_x_gradient, dst_x_gradient);
	convertScaleAbs(dst_y_gradient, dst_y_gradient);

	imshow("dst_x_gradient", dst_x_gradient);
	imshow("dst_y_gradient", dst_y_gradient);

	//合并梯度
	addWeighted(dst_x_gradient, 0.5, dst_y_gradient, 0.5, 0, dst_xy_gradient);
	imshow("dst_xy_gradient", dst_xy_gradient);

	waitKey(0);
	return 0;
}