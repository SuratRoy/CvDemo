#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;

//��̬ѧ������һ��Զ�ֵͼ����Ч�����
//���������ȸ�ʴ������
//�ղ����������ͺ�ʴ���뿪�����෴

int main013() {
	//������һ��ͼ�񣬱���Ϊ��ɫ��Ŀ��Ϊ��ɫ������Ҫͨ����̬ѧ����ȥ������
	Mat src = imread("Pictures\\11.png");
	imshow("src", src);
	Mat dst_open, dst_close;

	Mat k = getStructuringElement(MORPH_RECT, Size(5, 5));

	//�Ƚ��п�������ȥ������İ׵����
	morphologyEx(src, dst_open, CV_MOP_OPEN, k, Point(-1, -1), 2);  //2��5*5������
	imshow("dst_open", dst_open);

	//Ȼ���ٽ��бղ�����ȥ������ĺڵ����
	morphologyEx(dst_open, dst_close, CV_MOP_CLOSE, k, Point(-1, -1), 2);
	imshow("dst_close", dst_close);

	waitKey(0);
	return 0;
}