#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main028() {
	Mat src = imread("Pictures\\4.jpg");
	imshow("src", src);
	Mat comp = imread("Pictures\\4_comp.jpg");
	imshow("comp", comp);

	//转到hsv通道
	Mat src_hsv, comp_hsv;
	cvtColor(src, src_hsv, cv::ColorConversionCodes::COLOR_BGR2HSV);
	cvtColor(comp, comp_hsv, cv::ColorConversionCodes::COLOR_BGR2HSV);

	int channels[] = { 0, 1 };
	int h_bins = 180, s_bins = 256;
	int histSize[] = { h_bins ,s_bins };
	float h_range[] = { 0,180 };
	float s_range[] = { 0,256 };
	const float *histRange[] = { h_range,s_range };
	//分别计算直方图
	Mat hist_src, hist_comp;
	calcHist(&src_hsv, 1, channels, Mat(), hist_src, 2, histSize, histRange);
	calcHist(&comp_hsv, 1, channels, Mat(), hist_comp, 2, histSize, histRange);

	//归一化
	normalize(hist_src, hist_src, 0, 1, cv::NormTypes::NORM_MINMAX);
	normalize(hist_comp, hist_comp, 0, 1, cv::NormTypes::NORM_MINMAX);

	//比较直方图，这里用的是HISTCMP_CORREL方法，越接近1，代表越相似
	double res = compareHist(hist_src, hist_comp, cv::HistCompMethods::HISTCMP_CORREL);
	cout << "相似度：" << res << endl;

	waitKey(0);
	return 0;
}