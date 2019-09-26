#include <opencv2/opencv.hpp>
using namespace cv;

//��˹��ͬ(Difference of Gaussian - DOG)��
//���ǰ�ͬһ��ͼ���ڲ�ͬ�Ĳ���������˹ģ��֮��Ľ��������õ������ͼ�񡣳�Ϊ��˹��ͬ(DOG)
//��˹��ͬ��ͼ��������������ڻҶ�ͼ����ǿ���ǵ����о����õ���

int main() {
	Mat src = imread("Pictures\\5.jpg");
	imshow("src", src);

	//ת�Ҷ�ͼ
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	Mat g1, g2, dst_dog;
	//��˹ģ��
	GaussianBlur(gray, g1, Size(3, 3), 0);
	GaussianBlur(g1, g2, Size(3, 3), 0);
	//ͼ�����
	subtract(g1, g2, dst_dog);
	//��һ������
	//NORM_MINMAX:�������ֵ��ƽ�ƻ����ŵ�һ��ָ���ķ�Χ�����Թ�һ����һ��ϳ���
	normalize(dst_dog, dst_dog, 0, 255, cv::NormTypes::NORM_MINMAX);

	imshow("dst_dog", dst_dog);

	waitKey(0);
	return 0;
}