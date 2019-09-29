#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("Pictures\\16.png");
	imshow("src", src);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	//÷–÷µ¬À≤®£¨“÷÷∆Ω∑—Œ‘Î…˘
	medianBlur(gray, gray, 3);

	threshold(gray, gray, 254, 255, THRESH_BINARY);
	imshow("threshold", gray);

	vector<Vec3f> dst_circles;
	HoughCircles(gray, dst_circles, cv::HoughModes::HOUGH_GRADIENT, 1, 30, 100, 20, 10, 200);

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