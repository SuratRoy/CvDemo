#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


//����ͼ�����ȺͶԱȶ�
void conversion(Mat& src, double alpha, double beta, Mat& dst) {
	dst = Mat(src.size(), src.type());
	int width = src.cols;
	int height = src.rows;
	int channels = src.channels();
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (channels == 1) { //��ͨ��
				int gray = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(alpha * gray + beta);
			}
			else if (channels == 3) {  //��ͨ��
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(alpha * b + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(alpha * g + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(alpha * r + beta);
			}
		}
	}
}

int main() {
	Mat src = imread("Pictures\\1.png");
	imshow("src", src);

	Mat src_conversion;
	//�Աȶ�1.2������30
	conversion(src, 1.2, 30, src_conversion);
	imshow("src_conversion", src_conversion);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	Mat gray_conversion;
	//�Աȶ�0.8������-10
	conversion(gray, 0.8, -10, gray_conversion);
	imshow("gray_conversion", gray_conversion);

	waitKey(0);
	return 0;
}