#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat dst_gray32;

void ConvexDemo(int pos, void*) {
	Mat dst_canny;
	//Canny�㷨��ȡ��Ե
	Canny(dst_gray32, dst_canny, pos, pos * 2);

	imshow("dst_canny", dst_canny);

	//��ȡ����
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dst_canny, contours, hierarchy, cv::RetrievalModes::RETR_TREE, cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	//����ÿһ��������͹��
	vector<vector<Point>> convexs(contours.size());
	for (size_t i = 0; i < contours.size(); i++)
	{
		convexHull(contours[i], convexs[i]);
	}

	//����������͹��
	Mat dst_contours = Mat::zeros(dst_gray32.size(), CV_8UC3);
	Mat dst_convexs = Mat::zeros(dst_gray32.size(), CV_8UC3);
	RNG random(88888);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(random.uniform(0, 255), random.uniform(0, 255), random.uniform(0, 255));
		drawContours(dst_contours, contours, i, color, 1, LINE_AA, hierarchy, 0);
		drawContours(dst_convexs, convexs, i, color, 1, LINE_AA);
	}

	imshow("dst_contours", dst_contours);
	imshow("dst_convexs", dst_convexs);
}

int main032() {
	Mat src = imread("Pictures\\19.png");
	imshow("src", src);

	cvtColor(src, dst_gray32, CV_BGR2GRAY);

	int t1 = 50;
	ConvexDemo(t1, 0);
	createTrackbar("����ֵ", "dst_convexs", &t1, 255, ConvexDemo);

	waitKey(0);
	return 0;
}