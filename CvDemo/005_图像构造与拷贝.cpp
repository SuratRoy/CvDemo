#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main005() {
	//���캯��������һ��300*300��8λ3ͨ����ͼƬ������ÿ�����ص�Ϊ��0, 0, 255��
	Mat src(300, 300, CV_8UC3, Scalar(0, 0, 255));  //(B,G,R)
	imshow("src", src);

	//���ͼ��ʹ��clone��������������͸�ֵ���������ֻ����ͷ���֣�
	Mat dst = src.clone();
	imshow("dst", dst);
	waitKey(0);

	return 0;
}