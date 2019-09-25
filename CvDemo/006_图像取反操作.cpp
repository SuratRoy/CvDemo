#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


//ȡ��ͼ��
void negate(Mat& src, Mat& dst) {
#pragma region �Լ�ʵ�ֵ�ȡ������
	//dst = Mat(src.size(), src.type());
	//int width = src.cols;
	//int height = src.rows;
	//int channels = src.channels();
	//for (int row = 0; row < height; row++)
	//{
	//	for (int col = 0; col < width; col++)
	//	{
	//		if (channels == 1) { //��ͨ��
	//			int gray = src.at<uchar>(row, col);
	//			dst.at<uchar>(row, col) = 255 - gray;
	//		}
	//		else if (channels == 3) {  //��ͨ��
	//			int b = src.at<Vec3b>(row, col)[0];
	//			int g = src.at<Vec3b>(row, col)[1];
	//			int r = src.at<Vec3b>(row, col)[2];
	//			dst.at<Vec3b>(row, col)[0] = 255 - b;
	//			dst.at<Vec3b>(row, col)[1] = 255 - g;
	//			dst.at<Vec3b>(row, col)[2] = 255 - r;
	//		}
	//	}
	//}
#pragma endregion

	//opencv��ȡ������
	//1��ʹ��bitwise_not����
	//bitwise_not(src, dst);
	//2��ʹ��~�������������Ȼ���ָ��Ӽ��
	dst = ~src;
}

int main006() {
	Mat src = imread("Pictures\\1.png");
	imshow("src", src);

	Mat src_negate;
	negate(src, src_negate);
	imshow("src_negate", src_negate);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	Mat gray_negate;
	negate(gray, gray_negate);
	imshow("gray_negate", gray_negate);

	waitKey(0);
	return 0;
}