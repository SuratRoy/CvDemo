#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

int main016() {
	Mat src = imread("Pictures\\13.png");

	imshow("src", src);

	//��ֵ����Ҫ�Ƚ���ɫͼתΪ�Ҷ�ͼ
	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	Mat dst_binary;
	//��ֵ����������ֵΪ254��THRESH_BINARY_INV��CV_THRESH_BINARY�෴
	////THRESH_BINARY_INV���� value = value > 254 ? 0 : 255
	//���԰�ɫ��255����Ϊ��ɫ��0������������Ϊ��ɫ��255��
	threshold(src, dst_binary, 254, 255, THRESH_BINARY_INV);
	imshow("dst_binary", dst_binary);

	//��ȡˮƽ�봹ֱֱ��
	Mat dst_horizontal_line, dst_vertical_line;

	//����ˮƽ�ṹԪ��
	Mat horizontal_kernel = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(dst_binary.cols / 8, 1));
	//��ˮƽ�ṹԪ�ضԶ�ֵͼ���п���������ȡ��Ŀ��ͼ��
	morphologyEx(dst_binary, dst_horizontal_line, cv::MorphTypes::MORPH_OPEN, horizontal_kernel);
	imshow("dst_horizontal_line", dst_horizontal_line);

	//���崹ֱ�ṹԪ��
	Mat vertical_kernel = getStructuringElement(cv::MorphShapes::MORPH_RECT, Size(1, dst_binary.rows / 8));
	//�ô�ֱ�ṹԪ�ضԶ�ֵͼ���п���������ȡ��Ŀ��ͼ��
	morphologyEx(dst_binary, dst_vertical_line, cv::MorphTypes::MORPH_OPEN, vertical_kernel);
	imshow("dst_vertical_line", dst_vertical_line);

	waitKey(0);
	return 0;
}