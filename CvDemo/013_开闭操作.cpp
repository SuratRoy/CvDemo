#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;

//形态学操作，一般对二值图像处理效果最好
//开操作：先腐蚀后膨胀
//闭操作：先膨胀后腐蚀，与开操作相反

int main013() {
	//这里有一副图像，背景为黑色，目标为白色，现在要通过形态学操作去除干扰
	Mat src = imread("Pictures\\11.png");
	imshow("src", src);
	Mat dst_open, dst_close;

	Mat k = getStructuringElement(MORPH_RECT, Size(5, 5));

	//先进行开操作，去掉外面的白点干扰
	morphologyEx(src, dst_open, CV_MOP_OPEN, k, Point(-1, -1), 2);  //2次5*5开操作
	imshow("dst_open", dst_open);

	//然后再进行闭操作，去除里面的黑点干扰
	morphologyEx(dst_open, dst_close, CV_MOP_CLOSE, k, Point(-1, -1), 2);
	imshow("dst_close", dst_close);

	waitKey(0);
	return 0;
}