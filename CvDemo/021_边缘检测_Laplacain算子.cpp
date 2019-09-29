#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//1����˹�˲��������
	GaussianBlur(src, src, Size(3, 3), 0);

	//2��ת�Ҷ�ͼ
	Mat dst_gray;
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	//3��Laplacian������ȡ��Ե
	Mat dst_laplacian;
	Laplacian(dst_gray, dst_laplacian, CV_16S, 3);

	//4��ȡ����ֵ
	convertScaleAbs(dst_laplacian, dst_laplacian);

	imshow("dst_laplacian", dst_laplacian);

	waitKey(0);
	return 0;
}