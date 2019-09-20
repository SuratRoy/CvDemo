#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main007() {
	Mat src1 = imread("Pictures\\3.jpg");
	imshow("src1", src1);
	Mat src2 = imread("Pictures\\5.jpg");
	imshow("src2", src2);

	double alpha = 0.4;  //权重
	Mat dst;
	//图像混合（将两张相同大小相同类型的图片混合成一张图片，各自占不同的权重）
	addWeighted(src1, alpha, src2, 1 - alpha, 0, dst);
	imshow("dst", dst);

	waitKey(0);

	return 0;
}