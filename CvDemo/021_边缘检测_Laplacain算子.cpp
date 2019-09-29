#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//1、高斯滤波消除噪点
	GaussianBlur(src, src, Size(3, 3), 0);

	//2、转灰度图
	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	//3、Laplacian算子提取边缘
	Mat dst_laplacian;
	Laplacian(dst_gray, dst_laplacian, CV_16S, 3);

	//4、取绝对值
	convertScaleAbs(dst_laplacian, dst_laplacian);

	imshow("dst_laplacian", dst_laplacian);

	waitKey(0);
	return 0;
}