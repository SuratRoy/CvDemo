#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main011() {
	Mat src = imread("Pictures\\8.jpg");
	imshow("src", src);

	//˫���˲����е����������е�ĥƤЧ����
	//���������ͼ��Ŀռ��ڽ��Ⱥ�����ֵ���ƶȵ�һ�����д���ͬʱ���ǿ�����Ϣ�ͻҶ������ԣ��ﵽ����ȥ���Ŀ��
	//�ص㣺˫���˲����ĺô��ǿ�������Ե���棬һ���ø�˹�˲�ȥ���룬������Ե�ģ����Ե�����ڸ�Ƶϸ�ڵı���Ч���������ԡ�
	//˫���˲�������˼��ȸ�˹�˲�����һ����˹����sigma��d�����ǻ��ڿռ�ֲ��ĸ�˹�˲�������
	//�����ڱ�Ե��������Ľ�Զ�����ز���̫��Ӱ�쵽��Ե�ϵ�����ֵ�������ͱ�֤�˱�Ե��������ֵ�ı��档
	Mat dst_bilateral;
	bilateralFilter(src, dst_bilateral, 15, 100, 3);
	imshow("dst_˫���˲�", dst_bilateral);

	Mat dst_GaussianBlur;
	GaussianBlur(src, dst_GaussianBlur, Size(15, 15), 3, 3);
	imshow("dst_��˹�˲�", dst_GaussianBlur);

	waitKey(0);
	return 0;
}