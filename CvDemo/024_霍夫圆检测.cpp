#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main024() {
	Mat src = imread("Pictures\\17.png");
	imshow("src", src);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	//中值滤波，抑制椒盐噪声
	//medianBlur(gray, gray, 3);

	//检测符合条件的圆
	vector<Vec3f> dst_circles;
	HoughCircles(gray, dst_circles, cv::HoughModes::HOUGH_GRADIENT, 1, 10, 100, 50, 10, 100);

	//在源图上绘制显示
	Mat dst = src.clone();
	for (size_t i = 0; i < dst_circles.size(); i++)
	{
		Vec3f c = dst_circles[i];
		circle(dst, Point(c[0], c[1]), c[2], Scalar(0, 255, 0), 2);
		circle(dst, Point(c[0], c[1]), 2, Scalar(255, 0, 0), 2);
	}
	imshow("dst", dst);

	waitKey(0);
	return 0;
}