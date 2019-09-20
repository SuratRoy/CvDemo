#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//��ֵ�˲�
	//ԭ��ʹ��ģ�����������ص�ƽ��ֵ����ģ���������ػҶ�ֵ
	//���������յ������ĸ��ţ�������ȫ����������ֻ����Լ�������
	//Size�Ŀ�߶�����Ϊ��������ֵԽ��ģ��Խ���ԣ�Point(-1,-1)����ȡ���ģ�һ�㲻��Ҫ�޸�
	Mat dst_blur;
	blur(src, dst_blur, Size(13, 13), Point(-1, -1));
	imshow("dst_blur", dst_blur);

	//��˹�˲�
	//ԭ����ͼ�����������ؽ���ƽ��ʱ�������ڲ�ͬλ�õ����ر����費ͬ��Ȩֵ
	//��������ͼ�����ƽ����ͬʱ��ͬʱ�ܹ�����ı���ͼ�������Ҷȷֲ�����
	//��˹�˲�ģ��������Ҫ�Ĳ������Ǹ�˹�ֲ��ı�׼��ң�sigma����
	//�����������ݵ���ɢ�̶ȣ�����ҽ�С����ô���ɵ�ģ������ϵ��Խ�󣬶���Χ��ϵ��ԽС��������ͼ���ƽ��Ч���Ͳ��Ǻ����ԣ�
	//�෴���ҽϴ�ʱ�������ɵ�ģ��ĸ���ϵ�����Ͳ��Ǻܴ󣬱Ƚ������ھ�ֵģ�壬��ͼ���ƽ��Ч���ͱȽ����ԡ�
	//sigmaX����ʾ��˹�˺�����X����ĵı�׼ƫ��
	//sigmaY����ʾ��˹�˺�����Y����ĵı�׼ƫ���sigmaYΪ�㣬�ͽ�����ΪsigmaX�����sigmaX��sigmaY����0����ô����ksize.width��ksize.height���������
	Mat dst_GaussianBlur;
	GaussianBlur(src, dst_GaussianBlur, Size(13, 13), 2, 2);
	imshow("dst_GaussianBlur", dst_GaussianBlur);

	waitKey(0);
	return 0;
}