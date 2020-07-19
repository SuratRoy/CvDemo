#include <opencv2/opencv.hpp>
using namespace cv;

//Canny�㷨���� �C �岽 in cv::Canny
//1����˹ģ�� - GaussianBlur//2���Ҷ�ת�� - cvtColor//3�������ݶ� �C Sobel / Scharr//4��������ź����ƣ�ͨ����������ָѰ�����ص�ֲ����ֵ�����Ǽ���ֵ������Ӧ�ĻҶ�ֵ��Ϊ0�����������޳���һ�󲿷ַǱ�Ե�ĵ㣩//5���ߵ���ֵ�����ֵͼ��
//T1�� T2Ϊ��ֵ�����Ǹ���T2�Ķ�����������С��T1���������Ӹ���T2�����س��������Ǵ���T1�����໥���ӵģ������������յõ�һ�������ֵͼ��
//�Ƽ��ĸߵ���ֵ��ֵΪ T2: T1 = 3:1/2:1����T2Ϊ����ֵ��T1Ϊ����ֵ

Mat src22, dst_gray22;

void CannyDemo(int pos, void*) {
	Mat edges;
	//Canny�㷨��ȡ��Ե
	Canny(dst_gray22, edges, pos, pos * 2);
	//����ԵתΪ��ɫͼ��
	Mat dst;
	src22.copyTo(dst, edges);

	imshow("dst", dst);
}

int main022() {
	src22 = imread("Pictures\\6.jpg");
	imshow("src", src22);

	cvtColor(src22, dst_gray22, CV_BGR2GRAY);
	blur(dst_gray22, dst_gray22, Size(3, 3));

	imshow("dst_gray", dst_gray22);

	int t1 = 50;
	CannyDemo(t1, 0);
	createTrackbar("����ֵ", "dst", &t1, 255, CannyDemo);

	waitKey(0);
	return 0;
}