using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

int main017() {
	Mat src = imread("Pictures\\14.png");
	imshow("src", src);

	//ת�Ҷ�ͼ
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	//��ֵ��
	Mat binary;
	threshold(gray, binary, 254, 255, cv::ThresholdTypes::THRESH_BINARY);
	imshow("binary", binary);

	//����3*3�ĽṹԪ��
	Mat k = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(3, 3));
	Mat dst;
	//���ղ�����ȥ�����ţ��õ�Ŀ��ͼ��
	morphologyEx(binary, dst, cv::MorphTypes::MORPH_CLOSE, k);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}