#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("src_gray", gray);

	Mat dst;
	//ͼ����⻯��һ�����ͼ��Աȶȵķ���������ͼ��Ҷ�ֱ��ͼ
	equalizeHist(gray, dst);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}