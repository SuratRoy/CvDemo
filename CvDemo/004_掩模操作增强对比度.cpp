#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main004() {
	Mat src = imread("Pictures\\1.png");
	imshow("src", src);

#pragma region 手动实现掩模
	////根据源图像的大小和类型创建一副黑图（每个像素点为0,0,0）
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

#pragma region 使用opencv的函数实现掩模
	Mat dst;
	//定义一个小二维数组（3*3）
	Mat kernel = (Mat_<char>(3, 3) <<
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	cout << kernel << endl;  //打印这个数组
	filter2D(src, dst, src.depth(), kernel);
#pragma endregion

	imshow("dst", dst);
	waitKey(0);
	return 0;
}