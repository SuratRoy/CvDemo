#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;

//膨胀和腐蚀被称为形态学操作。它们通常在二进制图像上执行，类似于轮廓检测。
//通过将像素添加到该图像中的对象的感知边界，扩张放大图像中的明亮白色区域。腐蚀恰恰相反：它沿着物体边界移除像素并缩小物体的大小。
//通常这两个操作是按顺序执行的，以增强重要的对象特征！

//膨胀：输出像素 = 结构元素覆盖下输入像素最大值
//腐蚀：输出像素 = 结构元素覆盖下输入像素最小值

int main012() {
	Mat src = imread("Pictures\\10.png");
	imshow("src", src);

	Mat dst_dilate3;
	Mat dst_dilate_erode3;


	//Mat kernel = (Mat_<char>(3, 3) <<
	//	1, 1, 1,
	//	1, 1, 1,
	//	1, 1, 1);
	//生成3*3矩形（与以上语句完成相同）
	Mat kernel3 = getStructuringElement(MORPH_RECT, Size(3, 3));
	cout << kernel3 << endl;
	//3*3 膨胀5次 去除黑点干扰
	dilate(src, dst_dilate3, kernel3, Point(-1, -1), 5);
	imshow("dst_膨胀size(3,3)5次", dst_dilate3);
	//3*3 腐蚀5次 还原被膨胀的形状大小
	erode(dst_dilate3, dst_dilate_erode3, kernel3, Point(-1, -1), 5);
	imshow("dst_膨胀size(3,3)5次,之后腐蚀", dst_dilate_erode3);

	//膨胀和腐蚀通常用于去除干扰
	//目标形状是黑色，背景为白色，则应该先膨胀再腐蚀
	//目标形状是白色，背景为黑色，则应该先腐蚀再膨胀

	waitKey(0);
	return 0;
}