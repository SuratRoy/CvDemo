#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main005() {
	//构造函数，创建一副300*300的8位3通道的图片，其中每个像素点为（0, 0, 255）
	Mat src(300, 300, CV_8UC3, Scalar(0, 0, 255));  //(B,G,R)
	imshow("src", src);

	//深拷贝图像使用clone函数（拷贝构造和赋值运算符都是只复制头部分）
	Mat dst = src.clone();
	imshow("dst", dst);
	waitKey(0);

	return 0;
}