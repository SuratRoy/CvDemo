#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main007() {
	Mat src1 = imread("Pictures\\3.jpg");
	imshow("src1", src1);
	Mat src2 = imread("Pictures\\5.jpg");
	imshow("src2", src2);

	double alpha = 0.4;  //Ȩ��
	Mat dst;
	//ͼ���ϣ���������ͬ��С��ͬ���͵�ͼƬ��ϳ�һ��ͼƬ������ռ��ͬ��Ȩ�أ�
	addWeighted(src1, alpha, src2, 1 - alpha, 0, dst);
	imshow("dst", dst);

	waitKey(0);

	return 0;
}