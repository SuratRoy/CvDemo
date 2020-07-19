#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main030() {
	Mat src = imread("Pictures\\18.jpg");
	Mat temp = imread("Pictures\\18_temp.png");
	imshow("src", src);
	imshow("temp", temp);

	//ģ��ƥ�䣨����ʹ��TM_CCORR_NORMED�㷨�����ֵΪ��ƥ��ĵ㣩
	//ע�⣺�е��㷨����СֵΪ��ƥ��ĵ�
	Mat res;
	matchTemplate(src, temp, res, cv::TemplateMatchModes::TM_CCORR_NORMED);
	//normalize(res, res, 0, 1, NormTypes::NORM_MINMAX);
	imshow("res", res);  //����TM_CCORR_NORMED�㷨�Ѿ���һ���ˣ�����������������ʾͼƬ

	//��ȡ�����Сֵ����Ӧ�������
	double min_val, max_val;
	Point min_point, max_point;
	minMaxLoc(res, &min_val, &max_val, &min_point, &max_point);

	//��ƥ�䵽��λ�û�����ԭͼ�ϣ���ʾ���
	Mat dst;
	src.copyTo(dst);
	rectangle(dst, Rect(max_point.x, max_point.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, LINE_AA);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}