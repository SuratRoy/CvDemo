#include <iostream>
using namespace std;

//opencvͷ�ļ�
#include <opencv2/opencv.hpp>
using namespace cv;


int main001() {
	Mat src = imread("C:\\Users\\84566\\Pictures\\1.png");

	if (!src.empty()) {
		imshow("img", src);
		waitKey(0);
	}
	else
	{
		cout << "ͼƬ������" << endl;
		system("pause");
	}
	
	return 0;
}