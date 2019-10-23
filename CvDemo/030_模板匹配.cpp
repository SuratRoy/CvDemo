#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main030() {
	Mat src = imread("Pictures\\18.jpg");
	Mat temp = imread("Pictures\\18_temp.png");
	imshow("src", src);
	imshow("temp", temp);

	//模板匹配（这里使用TM_CCORR_NORMED算法，最大值为最匹配的点）
	//注意：有的算法是最小值为最匹配的点
	Mat res;
	matchTemplate(src, temp, res, cv::TemplateMatchModes::TM_CCORR_NORMED);
	//normalize(res, res, 0, 1, NormTypes::NORM_MINMAX);
	imshow("res", res);  //由于TM_CCORR_NORMED算法已经归一化了，所以这里能正常显示图片

	//获取最大最小值和相应的坐标点
	double min_val, max_val;
	Point min_point, max_point;
	minMaxLoc(res, &min_val, &max_val, &min_point, &max_point);

	//将匹配到的位置绘制在原图上，显示结果
	Mat dst;
	src.copyTo(dst);
	rectangle(dst, Rect(max_point.x, max_point.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, LINE_AA);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}