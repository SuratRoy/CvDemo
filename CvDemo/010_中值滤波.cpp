#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main() {
	Mat src = imread("Pictures\\9.jpg");
	imshow("src", src);

	//��ֵ�˲�
	//ԭ������ģ�������������е���ֵ�������������������ֵ���ģ���������صĻҶ�ֵ
	//�ص㣺������������ô���У��ܹ��Ϻõ����������������������׵���ͼ��Ĳ�������
	//��ֵ�˲��Խ���������ͼƬ�еİ׵���ߺڵ㣩�кܺõ���������
	Mat dst;
	medianBlur(src, dst, 7);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}