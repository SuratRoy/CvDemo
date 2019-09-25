#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

Mat dst_gray, dst_binary, dst_adaptive_binary;

void on_trackbar(int pos, void*)
{
	//全局二值化方法 threshold 方法，主要是通过遍历灰度图中点，将图像信息二值化，处理过后的图片只有二种色值
	//CV_THRESH_BINARY代表： value = value > pos ? 255 : 0 （灰度级大于阈值的像素被标记为255，否则为0）
	threshold(dst_gray, dst_binary, pos, 255, CV_THRESH_BINARY);
	namedWindow("全局二值化");
	imshow("全局二值化", dst_binary);
}


int blockSize = 3, C = 0;
void update_adaptive_binary() {
	//自适应二值化 adaptiveThreshold 方法，以像素的邻域的信息为基础来计算每一个像素的阈值
	//adaptiveMethod参数表示自适应阈值算法，平均 （ADAPTIVE_THRESH_MEAN_C）或高斯（ADAPTIVE_THRESH_GAUSSIAN_C）
	//thresholdType参数表示阈值类型，必须为THRESH_BINARY或THRESH_BINARY_INV的阈值类型
	//blockSize参数表示块大小（奇数且大于1，比如3，5，7........ ）
	//C参数是常数，表示从平均值或加权平均值中减去的数
	adaptiveThreshold(dst_gray, dst_adaptive_binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blockSize, C);
	namedWindow("自适应二值化");
	imshow("自适应二值化", dst_adaptive_binary);
}

void on_trackbar_blockSize(int pos, void*) {
	blockSize = pos * 2 + 1;
	update_adaptive_binary();
}

void on_trackbar_C(int pos, void*) {
	update_adaptive_binary();
}

int main() {
	Mat src = imread("Pictures\\6.jpg");

	imshow("src", src);

	//二值化需要先将彩色图转为灰度图
	cvtColor(src, dst_gray, CV_BGR2GRAY);
	imshow("dst_gray", dst_gray);

	int nThreshold = 80;
	on_trackbar(nThreshold, 0);
	createTrackbar("二值图阈值", "全局二值化", &nThreshold, 254, on_trackbar);


	update_adaptive_binary();

	int pos_blockSize = 1;
	createTrackbar("邻域块", "自适应二值化", &pos_blockSize, 30, on_trackbar_blockSize);
	setTrackbarMin("邻域块", "自适应二值化", 1);

	int pos_C = 0;
	createTrackbar("偏移值", "自适应二值化", &C, 50, on_trackbar_C);

	waitKey(0);
	return 0;
}
