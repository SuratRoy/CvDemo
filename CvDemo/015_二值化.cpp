#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

Mat dst_gray, dst_binary, dst_adaptive_binary;

void on_trackbar(int pos, void*)
{
	//ȫ�ֶ�ֵ������ threshold ��������Ҫ��ͨ�������Ҷ�ͼ�е㣬��ͼ����Ϣ��ֵ������������ͼƬֻ�ж���ɫֵ
	//CV_THRESH_BINARY���� value = value > pos ? 255 : 0 ���Ҷȼ�������ֵ�����ر����Ϊ255������Ϊ0��
	threshold(dst_gray, dst_binary, pos, 255, CV_THRESH_BINARY);
	namedWindow("ȫ�ֶ�ֵ��");
	imshow("ȫ�ֶ�ֵ��", dst_binary);
}


int blockSize = 3, C = 0;
void update_adaptive_binary() {
	//����Ӧ��ֵ�� adaptiveThreshold �����������ص��������ϢΪ����������ÿһ�����ص���ֵ
	//adaptiveMethod������ʾ����Ӧ��ֵ�㷨��ƽ�� ��ADAPTIVE_THRESH_MEAN_C�����˹��ADAPTIVE_THRESH_GAUSSIAN_C��
	//thresholdType������ʾ��ֵ���ͣ�����ΪTHRESH_BINARY��THRESH_BINARY_INV����ֵ����
	//blockSize������ʾ���С�������Ҵ���1������3��5��7........ ��
	//C�����ǳ�������ʾ��ƽ��ֵ���Ȩƽ��ֵ�м�ȥ����
	adaptiveThreshold(dst_gray, dst_adaptive_binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);
	namedWindow("����Ӧ��ֵ��");
	imshow("����Ӧ��ֵ��", dst_adaptive_binary);
}

void on_trackbar_blockSize(int pos, void*) {
	blockSize = pos * 2 + 1;
	update_adaptive_binary();
}

void on_trackbar_C(int pos, void*) {
	update_adaptive_binary();
}

int main() {
	Mat src = imread("Pictures\\6.jpg");

	imshow("src", src);

	//��ֵ����Ҫ�Ƚ���ɫͼתΪ�Ҷ�ͼ
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	int nThreshold = 80;
	on_trackbar(nThreshold, 0);
	createTrackbar("��ֵͼ��ֵ", "ȫ�ֶ�ֵ��", &nThreshold, 254, on_trackbar);


	update_adaptive_binary();

	int pos_blockSize = 1;
	createTrackbar("�����", "����Ӧ��ֵ��", &pos_blockSize, 30, on_trackbar_blockSize);
	setTrackbarMin("�����", "����Ӧ��ֵ��", 1);

	int pos_C = 0;
	createTrackbar("ƫ��ֵ", "����Ӧ��ֵ��", &C, 50, on_trackbar_C);

	waitKey(0);
	return 0;
}
