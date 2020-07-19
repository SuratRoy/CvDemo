#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

//1、提取图像边缘//2、发现轮廓//3、计算每个轮廓对象的矩//4、计算每个对象的中心、弧长、面积

Mat src34, gray_src34;

const char* output_win = "image moents demo";
RNG rng(12345);
void Demo_Moments(int, void*);
int main(int argc, char** argv) {
	src34 = imread("Pictures\\19.png");
	if (!src34.data) {
		printf("could not load image...\n");
		return -1;
	}
	cvtColor(src34, gray_src34, CV_BGR2GRAY);
	GaussianBlur(gray_src34, gray_src34, Size(3, 3), 0, 0);

	char input_win[] = "input image";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow(input_win, src34);

	int threshold_value = 80;
	createTrackbar("Threshold Value : ", output_win, &threshold_value, 255, Demo_Moments);
	Demo_Moments(0, 0);

	waitKey(0);
	return 0;
}

void Demo_Moments(int pos, void*) {
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	Canny(gray_src34, canny_output, pos, pos * 2, 3, false);
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<Moments> contours_moments(contours.size());
	vector<Point2f> ccs(contours.size());
	for (size_t i = 0; i < contours.size(); i++) {
		contours_moments[i] = moments(contours[i]);
		ccs[i] = Point(static_cast<float>(contours_moments[i].m10 / contours_moments[i].m00), static_cast<float>(contours_moments[i].m01 / contours_moments[i].m00));
	}

	Mat drawImg;// = Mat::zeros(src.size(), CV_8UC3);
	src34.copyTo(drawImg);
	for (size_t i = 0; i < contours.size(); i++) {
		if (contours[i].size() < 100) {
			continue;
		}
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		printf("轮廓 %d 面积 : %.2f   长度 : %.2f\n", i, contourArea(contours[i]), arcLength(contours[i], true));
		printf("中心点 x : %.2f y : %.2f\n", ccs[i].x, ccs[i].y);
		drawContours(drawImg, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
		circle(drawImg, ccs[i], 2, color,2, 8);
	}

	imshow(output_win, drawImg);
	return;
}