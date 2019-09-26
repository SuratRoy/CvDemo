#include <opencv2/opencv.hpp>
using namespace cv;

//高斯不同(Difference of Gaussian - DOG)：
//就是把同一张图像在不同的参数下做高斯模糊之后的结果相减，得到的输出图像。称为高斯不同(DOG)
//高斯不同是图像的内在特征，在灰度图像增强、角点检测中经常用到。

int main() {
	Mat src = imread("Pictures\\5.jpg");
	imshow("src", src);

	//转灰度图
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);

	Mat g1, g2, dst_dog;
	//高斯模糊
	GaussianBlur(gray, g1, Size(3, 3), 0);
	GaussianBlur(g1, g2, Size(3, 3), 0);
	//图像相减
	subtract(g1, g2, dst_dog);
	//归一化处理
	//NORM_MINMAX:数组的数值被平移或缩放到一个指定的范围，线性归一化，一般较常用
	normalize(dst_dog, dst_dog, 0, 255, cv::NormTypes::NORM_MINMAX);

	imshow("dst_dog", dst_dog);

	waitKey(0);
	return 0;
}