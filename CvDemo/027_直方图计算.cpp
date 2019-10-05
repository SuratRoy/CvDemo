#include <opencv2/opencv.hpp>
using namespace cv;

using namespace std;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src",src);

	Mat src_bgr[3];
	//����ͨ��ͼƬ��ֳ�������ͨ��ͼƬ
	split(src, src_bgr);

	Mat hist_b, hist_g, hist_r;
	int histSize = 256;
	float range[] = { 0,256 };
	const float *histRange = { range };

	//����������ͨ��ͼƬ��ֱ��ͼ
	calcHist(&src_bgr[0], 1, 0, Mat(), hist_b, 1, &histSize, &histRange);
	calcHist(&src_bgr[1], 1, 0, Mat(), hist_g, 1, &histSize, &histRange);
	calcHist(&src_bgr[2], 1, 0, Mat(), hist_r, 1, &histSize, &histRange);

#pragma region ����ֱ��ͼ
	int bin_w = 2; //ֱ��ͼX����ļ��
	int height = 400, width = bin_w * histSize;  //ֱ��ͼ���

	//��ֱ��ͼ�����һ�������500��
	normalize(hist_b, hist_b, 0, height, cv::NormTypes::NORM_MINMAX);
	normalize(hist_g, hist_g, 0, height, cv::NormTypes::NORM_MINMAX);
	normalize(hist_r, hist_r, 0, height, cv::NormTypes::NORM_MINMAX);

	//����������ͼ�����ڻ���ֱ��ͼ
	Mat dst_b(height, width, CV_8UC3, Scalar(0, 0, 0));
	Mat dst_g = dst_b.clone();
	Mat dst_r = dst_b.clone();

	//���Ʋ���ʾֱ��ͼ
	for (size_t i = 0; i < histSize; i++)
	{
		float val_b = round(hist_b.at<float>(i));
		float val_g = round(hist_g.at<float>(i));
		float val_r = round(hist_r.at<float>(i));
		line(dst_b, Point(i*bin_w, height - val_b), Point(i*bin_w, height), Scalar(255, 0, 0));
		line(dst_g, Point(i*bin_w, height - val_g), Point(i*bin_w, height), Scalar(0, 255, 0));
		line(dst_r, Point(i*bin_w, height - val_r), Point(i*bin_w, height), Scalar(0, 0, 255));
	}
	imshow("ֱ��ͼ_b", dst_b);
	imshow("ֱ��ͼ_g", dst_g);
	imshow("ֱ��ͼ_r", dst_r);
#pragma endregion

	waitKey(0);
	return 0;
}