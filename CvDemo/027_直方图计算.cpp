#include <opencv2/opencv.hpp>
using namespace cv;

using namespace std;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src",src);

	Mat src_bgr[3];
	//将三通道图片拆分成三幅单通道图片
	split(src, src_bgr);

	Mat hist_b, hist_g, hist_r;
	int histSize = 256;
	float range[] = { 0,256 };
	const float *histRange = { range };

	//计算三幅单通道图片的直方图
	calcHist(&src_bgr[0], 1, 0, Mat(), hist_b, 1, &histSize, &histRange);
	calcHist(&src_bgr[1], 1, 0, Mat(), hist_g, 1, &histSize, &histRange);
	calcHist(&src_bgr[2], 1, 0, Mat(), hist_r, 1, &histSize, &histRange);

#pragma region 绘制直方图
	int bin_w = 2; //直方图X方向的间距
	int height = 400, width = bin_w * histSize;  //直方图宽高

	//将直方图结果归一化（最大500）
	normalize(hist_b, hist_b, 0, height, cv::NormTypes::NORM_MINMAX);
	normalize(hist_g, hist_g, 0, height, cv::NormTypes::NORM_MINMAX);
	normalize(hist_r, hist_r, 0, height, cv::NormTypes::NORM_MINMAX);

	//创建三幅黑图，用于绘制直方图
	Mat dst_b(height, width, CV_8UC3, Scalar(0, 0, 0));
	Mat dst_g = dst_b.clone();
	Mat dst_r = dst_b.clone();

	//绘制并显示直方图
	for (size_t i = 0; i < histSize; i++)
	{
		float val_b = round(hist_b.at<float>(i));
		float val_g = round(hist_g.at<float>(i));
		float val_r = round(hist_r.at<float>(i));
		line(dst_b, Point(i*bin_w, height - val_b), Point(i*bin_w, height), Scalar(255, 0, 0));
		line(dst_g, Point(i*bin_w, height - val_g), Point(i*bin_w, height), Scalar(0, 255, 0));
		line(dst_r, Point(i*bin_w, height - val_r), Point(i*bin_w, height), Scalar(0, 0, 255));
	}
	imshow("直方图_b", dst_b);
	imshow("直方图_g", dst_g);
	imshow("直方图_r", dst_r);
#pragma endregion

	waitKey(0);
	return 0;
}