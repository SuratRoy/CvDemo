#include <iostream>
using namespace std;

//opencv头文件
#include <opencv2/opencv.hpp>
using namespace cv;


int main() {
	Mat src = imread("Pictures\\6.jpg");
	imshow("src", src);

	//均值滤波
	//原理：使用模板内所有像素的平均值代替模板中心像素灰度值
	//特征：易收到噪声的干扰，不能完全消除噪声，只能相对减弱噪声
	//Size的宽高都必须为基数，数值越大，模糊越明显；Point(-1,-1)代表取中心，一般不需要修改
	Mat dst_blur;
	blur(src, dst_blur, Size(13, 13), Point(-1, -1));
	imshow("dst_blur", dst_blur);

	//高斯滤波
	//原理：对图像邻域内像素进行平滑时，邻域内不同位置的像素被赋予不同的权值
	//特征：对图像进行平滑的同时，同时能够更多的保留图像的总体灰度分布特征
	//高斯滤波模板中最重要的参数就是高斯分布的标准差σ（sigma）。
	//它代表着数据的离散程度，如果σ较小，那么生成的模板中心系数越大，而周围的系数越小，这样对图像的平滑效果就不是很明显；
	//相反，σ较大时，则生成的模板的各个系数相差就不是很大，比较类似于均值模板，对图像的平滑效果就比较明显。
	//sigmaX，表示高斯核函数在X方向的的标准偏差
	//sigmaY，表示高斯核函数在Y方向的的标准偏差。若sigmaY为零，就将它设为sigmaX，如果sigmaX和sigmaY都是0，那么就由ksize.width和ksize.height计算出来。
	Mat dst_GaussianBlur;
	GaussianBlur(src, dst_GaussianBlur, Size(13, 13), 2, 2);
	imshow("dst_GaussianBlur", dst_GaussianBlur);

	waitKey(0);
	return 0;
}