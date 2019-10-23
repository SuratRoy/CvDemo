#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//轮廓图像和Canny图像乍看起来表现几乎是一致的，但其实组成两者的数据结构差别很大：

//Canny边缘图像只是一些相互独立的散点勾勒出了一个边界，点与点之间没有联系，是没有“思想”的；

//轮廓图像是一系列的点组成的，相邻的点与点同属于一个轮廓“集合”，连续的点构成了一个整体，
//甚至我们可以通过编号对每个轮廓定位，定义其前后轮廓线段，内外轮廓包含、隶属等树形关系，是有“思想”，可进一步处理的。


Mat dst_gray31;

void ContoursDemo(int pos, void*) {
	Mat dst_canny;
	//Canny算法提取边缘
	Canny(dst_gray31, dst_canny, pos, pos * 2);

	imshow("dst_canny", dst_canny);

	//提取轮廓
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dst_canny, contours, hierarchy, cv::RetrievalModes::RETR_TREE, cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	//绘制轮廓
	Mat dst = Mat::zeros(dst_gray31.size(), CV_8UC3);
	RNG random(88888);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(random.uniform(0, 255), random.uniform(0, 255), random.uniform(0, 255));
		drawContours(dst, contours, i, color, 1, LINE_AA, hierarchy, 0);
	}

	imshow("dst_contours", dst);
}

int main() {
	Mat src = imread("Pictures\\16.png");
	imshow("src", src);

	cvtColor(src, dst_gray31, CV_BGR2GRAY);
	
	int t1 = 50;
	ContoursDemo(t1, 0);
	createTrackbar("低阈值", "dst_contours", &t1, 255, ContoursDemo);

	waitKey(0);
	return 0;
}