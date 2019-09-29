#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main023() {
	Mat src = imread("Pictures\\15.png");
	imshow("src", src);

	//对一个填充的六边形提取轮廓
	Mat dst_canny;
	Canny(src, dst_canny, 100, 200);
	imshow("dst_canny", dst_canny);

	//在轮廓中提取直线
	vector<Vec4f> hlines;
	HoughLinesP(dst_canny, hlines, 1, CV_PI / 180.0, 20, 0, 10);

	//将轮廓图转换为彩色图（Canny算法后会转为灰度图）
	Mat dst;
	cvtColor(dst_canny, dst, CV_GRAY2BGR);

	//在彩色图上绘制直线，显示输出
	for (size_t i = 0; i < hlines.size(); i++)
	{
		Vec4f hline = hlines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), Scalar(0, 0, 255), 1, cv::LineTypes::LINE_AA);
	}
	imshow("dst", dst);

	waitKey(0);
	return 0;
}