#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;

//形态学操作，一般对二值图像处理效果最好
//顶帽操作=开操作-源图像
//黑帽操作=闭操作-源图像

int main014() {
	Mat src = imread("Pictures\\11.png");
	imshow("src", src);
	Mat dst_顶帽, dst_黑帽;

	Mat k = getStructuringElement(MORPH_RECT, Size(9, 9));

	//顶帽操作，获取开操作被去掉的部分
	morphologyEx(src, dst_顶帽, CV_MOP_TOPHAT, k);
	imshow("dst_顶帽", dst_顶帽);

	//黑帽操作，获取闭操作被去掉的部分
	morphologyEx(src, dst_黑帽, CV_MOP_BLACKHAT, k);
	imshow("dst_黑帽", dst_黑帽);

	waitKey(0);
	return 0;
}