#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main() {
	Mat src = imread("Pictures\\9.jpg");
	imshow("src", src);

	//中值滤波
	//原理：计算模板内所有像素中的中值，并用所计算出来的中值体改模板中心像素的灰度值
	//特点：对噪声不是那么敏感，能够较好的消除椒盐噪声，但是容易导致图像的不连续性
	//中值滤波对椒盐噪声（图片中的白点或者黑点）有很好的抑制作用
	Mat dst;
	medianBlur(src, dst, 7);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}