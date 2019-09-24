#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;

//���ͺ͸�ʴ����Ϊ��̬ѧ����������ͨ���ڶ�����ͼ����ִ�У�������������⡣
//ͨ����������ӵ���ͼ���еĶ���ĸ�֪�߽磬���ŷŴ�ͼ���е�������ɫ���򡣸�ʴǡǡ�෴������������߽��Ƴ����ز���С����Ĵ�С��
//ͨ�������������ǰ�˳��ִ�еģ�����ǿ��Ҫ�Ķ���������

//���ͣ�������� = �ṹԪ�ظ����������������ֵ
//��ʴ��������� = �ṹԪ�ظ���������������Сֵ

int main012() {
	Mat src = imread("Pictures\\10.png");
	imshow("src", src);

	Mat dst_dilate3;
	Mat dst_dilate_erode3;


	//Mat kernel = (Mat_<char>(3, 3) <<
	//	1, 1, 1,
	//	1, 1, 1,
	//	1, 1, 1);
	//����3*3���Σ���������������ͬ��
	Mat kernel3 = getStructuringElement(MORPH_RECT, Size(3, 3));
	cout << kernel3 << endl;
	//3*3 ����5�� ȥ���ڵ����
	dilate(src, dst_dilate3, kernel3, Point(-1, -1), 5);
	imshow("dst_����size(3,3)5��", dst_dilate3);
	//3*3 ��ʴ5�� ��ԭ�����͵���״��С
	erode(dst_dilate3, dst_dilate_erode3, kernel3, Point(-1, -1), 5);
	imshow("dst_����size(3,3)5��,֮��ʴ", dst_dilate_erode3);

	//���ͺ͸�ʴͨ������ȥ������
	//Ŀ����״�Ǻ�ɫ������Ϊ��ɫ����Ӧ���������ٸ�ʴ
	//Ŀ����״�ǰ�ɫ������Ϊ��ɫ����Ӧ���ȸ�ʴ������

	waitKey(0);
	return 0;
}