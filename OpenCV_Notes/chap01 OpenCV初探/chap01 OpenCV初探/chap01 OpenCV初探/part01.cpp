//显示图片
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:\\Local_Workstation\\sys_File\\GitHub_worksation\\Study_Notes\\OpenCV_Notes\\chap01 OpenCV初探\\chap01 OpenCV初探\\src\\logo.png");
	if (src.empty())
	{
		cout << "读取失败" << endl;

	}
	else
	{
		namedWindow("EXAMPLE", WINDOW_AUTOSIZE);	// 可省略
		imshow("EXAMPLE", src);
	}
	waitKey(0);	//等待键盘输入
	destroyWindow("EXAMPLE");	//可省略
	return 0;
}