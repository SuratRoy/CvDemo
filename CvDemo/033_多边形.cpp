#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat dst_gray33;

void PolyDemo(int pos, void*) {
	Mat dst_canny;
	//Canny�㷨��ȡ��Ե
	Canny(dst_gray33, dst_canny, pos, pos * 2);

	imshow("dst_canny", dst_canny);

	//��ȡ����
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dst_canny, contours, hierarchy, cv::RetrievalModes::RETR_TREE, cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	vector<vector<Point>> polys(contours.size()); //�����
	vector<Rect> rects(contours.size());  //��Ӿ��Σ�0�ȣ�
	vector<Point2f> centers(contours.size());  //Բ��
	vector<float> radius(contours.size());  //�뾶
	for (size_t i = 0; i < contours.size(); i++)
	{
		approxPolyDP(contours[i], polys[i], 3, true);  //��ȡ����Σ����������ĵ㣩
		rects[i] = boundingRect(polys[i]);  //������Ӿ���
		minEnclosingCircle(polys[i], centers[i], radius[i]);  //�������Բ
	}

	//����������͹��
	Mat dst_contours = Mat::zeros(dst_gray33.size(), CV_8UC3);
	Mat dst_polys = Mat::zeros(dst_gray33.size(), CV_8UC3);
	RNG random(88888);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 255);
		drawContours(dst_contours, contours, i, color, 1, LINE_AA, hierarchy, 0);
		drawContours(dst_polys, polys, i, color, 1, LINE_AA);

		Scalar color_rect = Scalar(0, 255, 0);
		rectangle(dst_polys, rects[i], color_rect, 1, LINE_AA);
		Scalar color_circle = Scalar(255, 0, 0);
		circle(dst_polys, centers[i], radius[i], color_circle, 1, LINE_AA);
	}
	
	imshow("dst_contours", dst_contours);
	imshow("dst_polys", dst_polys);
}

int main033() {
	Mat src = imread("Pictures\\19.png");
	imshow("src", src);

	cvtColor(src, dst_gray33, CV_BGR2GRAY);

	int t1 = 50;
	PolyDemo(t1, 0);
	createTrackbar("����ֵ", "dst_polys", &t1, 255, PolyDemo);

	waitKey(0);
	return 0;
}