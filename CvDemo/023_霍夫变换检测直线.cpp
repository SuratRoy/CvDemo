#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main023() {
	Mat src = imread("Pictures\\15.png");
	imshow("src", src);

	//��һ��������������ȡ����
	Mat dst_canny;
	Canny(src, dst_canny, 100, 200);
	imshow("dst_canny", dst_canny);

	//����������ȡֱ��
	vector<Vec4f> hlines;
	HoughLinesP(dst_canny, hlines, 1, CV_PI / 180.0, 20, 0, 10);

	//������ͼת��Ϊ��ɫͼ��Canny�㷨���תΪ�Ҷ�ͼ��
	Mat dst;
	cvtColor(dst_canny, dst, CV_GRAY2BGR);

	//�ڲ�ɫͼ�ϻ���ֱ�ߣ���ʾ���
	for (size_t i = 0; i < hlines.size(); i++)
	{
		Vec4f hline = hlines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), Scalar(0, 0, 255), 1, cv::LineTypes::LINE_AA);
	}
	imshow("dst", dst);

	waitKey(0);
	return 0;
}