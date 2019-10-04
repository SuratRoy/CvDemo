#include <opencv2/opencv.hpp>
using namespace cv;

int main025() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//X����ӳ����У�
	Mat map_x(src.size(), CV_32FC1);
	//Y����ӳ����У�
	Mat map_y(src.size(), CV_32FC1);

	for (size_t row = 0; row < src.rows; row++)
	{
		for (size_t col = 0; col < src.cols; col++)
		{
			map_y.at<float>(row, col) = src.rows - row - 1;
			map_x.at<float>(row, col) = src.cols - col - 1;
		}
	}
	Mat dst;
	//ͨ��������ӳ�䣬��ͼ����ת180��
	remap(src, dst, map_x, map_y, cv::InterpolationFlags::INTER_NEAREST);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}