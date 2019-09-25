#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;

#include <functional>

void print3(int i) {
	cout << i << endl;
}

void print2(vector<int> & arr) {
	for_each(arr.begin(), arr.end(), print3);
}

void GetBarcode1DArr(Mat &bmpMat, vector<vector<int>> & const dst);

int main003() {
	Mat src = imread("Pictures\\1.png");
	imshow("src", src);

	Mat dst;
	//��ͼ���һ��ɫ�ʿռ�ת������һ��ɫ�ʿռ�
	cvtColor(src, dst, CV_BGR2GRAY);  //��BGRͼƬת�ɻҶ�ͼ
	imshow("dst", dst);

	//����ͼƬ
	imwrite("Pictures\\1_gray.png", dst);

	const int col = src.cols;
	const int row = src.rows;
	//����vector������ά����
	vector<vector<int>> arr(row, vector<int>(col));

	GetBarcode1DArr(src, arr);

	for_each(arr.begin(), arr.end(), print2);

	waitKey(0);

	return 0;
}



void GetBarcode1DArr(Mat &bmpMat, vector<vector<int>> & dst)
{
	Mat temp;
	cv::cvtColor(bmpMat, temp, CV_BGR2GRAY); //ת�ɻҶ�ͼ

	for (int row = 0; row < temp.rows; row++)
	{
		for (int col = 0; col < temp.cols; col++)
		{
			dst[row][col] = temp.at<uchar>(row, col);
		}
	}
}