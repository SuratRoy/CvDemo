#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;

//��̬ѧ����
//�������������ͺ�ʴ
//�ղ������ȸ�ʴ�����ͣ��뿪�����෴

int main() {
	//������һ��ͼ�񣬱���Ϊ��ɫ��Ŀ��Ϊ��ɫ������Ҫͨ����̬ѧ����ȥ������
	Mat src = imread("Pictures\\11.png");
	imshow("src", src);
	Mat dst_open, dst_close;

	Mat k = getStructuringElement(MORPH_RECT, Size(9, 9));

	//�Ƚ��п�������ȥ������İ׵����
	morphologyEx(src, dst_open, CV_MOP_OPEN, k);
	imshow("dst_open", dst_open);

	//Ȼ���ٽ��бղ�����ȥ������ĺڵ����
	morphologyEx(dst_open, dst_close, CV_MOP_CLOSE, k);
	imshow("dst_close", dst_close);

	waitKey(0);
	return 0;
}