#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//ת��hsvͨ��
	Mat src_hsv;
	cvtColor(src, src_hsv, cv::ColorConversionCodes::COLOR_BGR2HSV);

	Mat src_arr[3];
	//��hsv��ͨ��ͼƬ��ֳ�������ͨ��ͼƬ
	split(src_hsv, src_arr);

	Mat src_h = src_arr[0];
	imshow("hͨ��", src_h);

	//����ֱ��ͼ
	int h_bins = 60;
	int histSize[] = { h_bins };
	float h_range[] = { 0,180 };
	const float *histRange[] = { h_range };
	//����ֱ��ͼ
	Mat hist_h;
	calcHist(&src_h, 1, 0, Mat(), hist_h, 1, histSize, histRange);
	//��һ��
	normalize(hist_h, hist_h, 0, 255, cv::NormTypes::NORM_MINMAX);

	//����ӳ��
	Mat dst;
	calcBackProject(&src_h, 1, 0, hist_h, dst, histRange);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}