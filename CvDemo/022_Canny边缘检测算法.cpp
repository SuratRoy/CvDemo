#include <opencv2/opencv.hpp>
using namespace cv;

//Canny算法介绍 – 五步 in cv::Canny
//1、高斯模糊 - GaussianBlur//2、灰度转换 - cvtColor//3、计算梯度 – Sobel / Scharr//4、非最大信号抑制（通俗意义上是指寻找像素点局部最大值，将非极大值点所对应的灰度值置为0，这样可以剔除掉一大部分非边缘的点）//5、高低阈值输出二值图像
//T1， T2为阈值，凡是高于T2的都保留，凡是小于T1都丢弃，从高于T2的像素出发，凡是大于T1而且相互连接的，都保留。最终得到一个输出二值图像
//推荐的高低阈值比值为 T2: T1 = 3:1/2:1其中T2为高阈值，T1为低阈值

Mat src22, dst_gray22;

void CannyDemo(int pos, void*) {
	Mat edges;
	//Canny算法提取边缘
	Canny(dst_gray22, edges, pos, pos * 2);
	//将边缘转为彩色图像
	Mat dst;
	src22.copyTo(dst, edges);

	imshow("dst", dst);
}

int main022() {
	src22 = imread("Pictures\\6.jpg");
	imshow("src", src22);

	cvtColor(src22, dst_gray22, CV_BGR2GRAY);
	blur(dst_gray22, dst_gray22, Size(3, 3));

	imshow("dst_gray", dst_gray22);

	int t1 = 50;
	CannyDemo(t1, 0);
	createTrackbar("低阈值", "dst", &t1, 255, CannyDemo);

	waitKey(0);
	return 0;
}