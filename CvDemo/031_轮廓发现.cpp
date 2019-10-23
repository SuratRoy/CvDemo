#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//����ͼ���Cannyͼ��է���������ּ�����һ�µģ�����ʵ������ߵ����ݽṹ���ܴ�

//Canny��Եͼ��ֻ��һЩ�໥������ɢ�㹴�ճ���һ���߽磬�����֮��û����ϵ����û�С�˼�롱�ģ�

//����ͼ����һϵ�еĵ���ɵģ����ڵĵ����ͬ����һ�����������ϡ��������ĵ㹹����һ�����壬
//�������ǿ���ͨ����Ŷ�ÿ��������λ��������ǰ�������߶Σ������������������������ι�ϵ�����С�˼�롱���ɽ�һ������ġ�


Mat dst_gray31;

void ContoursDemo(int pos, void*) {
	Mat dst_canny;
	//Canny�㷨��ȡ��Ե
	Canny(dst_gray31, dst_canny, pos, pos * 2);

	imshow("dst_canny", dst_canny);

	//��ȡ����
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dst_canny, contours, hierarchy, cv::RetrievalModes::RETR_TREE, cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	//��������
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
	createTrackbar("����ֵ", "dst_contours", &t1, 255, ContoursDemo);

	waitKey(0);
	return 0;
}