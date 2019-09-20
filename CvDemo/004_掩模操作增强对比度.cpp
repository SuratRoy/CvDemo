#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main004() {
	Mat src = imread("Pictures\\1.png");
	imshow("src", src);

#pragma region �ֶ�ʵ����ģ
	////����Դͼ��Ĵ�С�����ʹ���һ����ͼ��ÿ�����ص�Ϊ0,0,0��
	//Mat dst = Mat::zeros(src.size(), src.type());
	//int offsetx = src.channels();
	//int row = src.rows;
	//int cols = src.cols * offsetx;
	//for (int i = 1; i < row - 1; i++)
	//{
	//	uchar *current = src.ptr<uchar>(i);
	//	uchar *before = src.ptr<uchar>(i - 1);
	//	uchar *after = src.ptr<uchar>(i + 1);
	//	uchar *output = dst.ptr<uchar>(i);
	//	for (int j = offsetx; j < cols - offsetx; j++)
	//	{
	//		output[j] = saturate_cast<uchar>(current[j] * 5 - (current[j - offsetx] + current[j + offsetx] + before[j] + after[j]));
	//	}
	//}
#pragma endregion

#pragma region ʹ��opencv�ĺ���ʵ����ģ
	Mat dst;
	//����һ��С��ά���飨3*3��
	Mat kernel = (Mat_<char>(3, 3) <<
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	cout << kernel << endl;  //��ӡ�������
	filter2D(src, dst, src.depth(), kernel);
#pragma endregion

	imshow("dst", dst);
	waitKey(0);
	return 0;
}