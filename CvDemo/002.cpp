#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main002() {
	//���ػҶ�ͼ
	Mat src = imread("Pictures\\1.png", 0);
	imshow("img", src);
	waitKey(0);

	return 0;
}