#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//��˹�˲��������
	GaussianBlur(src, src, Size(3, 3), 0);

	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	//����Sobel������X,Y������ݶ�
	Mat dst_x_gradient, dst_y_gradient, dst_xy_gradient;
	//��X�����ݶ�
	Sobel(dst_gray, dst_x_gradient, CV_16S, 1, 0);
	//��Y�����ݶ�
	Sobel(dst_gray, dst_y_gradient, CV_16S, 0, 1);
	//ȡ����ֵ
	convertScaleAbs(dst_x_gradient, dst_x_gradient);
	convertScaleAbs(dst_y_gradient, dst_y_gradient);

	imshow("dst_x_gradient", dst_x_gradient);
	imshow("dst_y_gradient", dst_y_gradient);

	//�ϲ��ݶ�
	addWeighted(dst_x_gradient, 0.5, dst_y_gradient, 0.5, 0, dst_xy_gradient);
	imshow("dst_xy_gradient", dst_xy_gradient);

	waitKey(0);
	return 0;
}