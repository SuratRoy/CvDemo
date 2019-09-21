#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main011() {
	Mat src = imread("Pictures\\8.jpg");
	imshow("src", src);

	//双边滤波（有点类似美颜中的磨皮效果）
	//描述：结合图像的空间邻近度和像素值相似度的一种折中处理，同时考虑空域信息和灰度相似性，达到保边去噪的目的
	//特点：双边滤波器的好处是可以做边缘保存，一般用高斯滤波去降噪，会较明显地模糊边缘，对于高频细节的保护效果并不明显。
	//双边滤波器顾名思义比高斯滤波多了一个高斯方差sigma－d，它是基于空间分布的高斯滤波函数，
	//所以在边缘附近，离的较远的像素不会太多影响到边缘上的像素值，这样就保证了边缘附近像素值的保存。
	Mat dst_bilateral;
	bilateralFilter(src, dst_bilateral, 15, 100, 3);
	imshow("dst_双边滤波", dst_bilateral);

	Mat dst_GaussianBlur;
	GaussianBlur(src, dst_GaussianBlur, Size(15, 15), 3, 3);
	imshow("dst_高斯滤波", dst_GaussianBlur);

	waitKey(0);
	return 0;
}