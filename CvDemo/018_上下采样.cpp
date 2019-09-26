#include <opencv2/opencv.hpp>
using namespace cv;

int main018() {
	Mat src = imread("Pictures\\5.jpg");
	imshow("src", src);

	Mat dst_up, dst_down;

	//�ϲ�����ͼ��Ŵ󣬿�߱�ΪԴͼ2��
	pyrUp(src, dst_up);
	imshow("dst_up", dst_up);

	//�²�����ͼ����С����߱�ΪԴͼ����֮һ
	pyrDown(src, dst_down);
	imshow("dst_down", dst_down);

	waitKey(0);
	return 0;
}