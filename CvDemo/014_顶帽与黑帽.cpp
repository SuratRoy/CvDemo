#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;

//��̬ѧ������һ��Զ�ֵͼ����Ч�����
//��ñ����=������-Դͼ��
//��ñ����=�ղ���-Դͼ��

int main014() {
	Mat src = imread("Pictures\\11.png");
	imshow("src", src);
	Mat dst_��ñ, dst_��ñ;

	Mat k = getStructuringElement(MORPH_RECT, Size(9, 9));

	//��ñ��������ȡ��������ȥ���Ĳ���
	morphologyEx(src, dst_��ñ, CV_MOP_TOPHAT, k);
	imshow("dst_��ñ", dst_��ñ);

	//��ñ��������ȡ�ղ�����ȥ���Ĳ���
	morphologyEx(src, dst_��ñ, CV_MOP_BLACKHAT, k);
	imshow("dst_��ñ", dst_��ñ);

	waitKey(0);
	return 0;
}