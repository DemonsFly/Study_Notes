// ”∆µ
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap;
	Mat frame;
	bool ret = cap.open("D:\\Local_Workstation\\sys_File\\GitHub_worksation\\Study_Notes\\OpenCV_Notes\\chap01 OpenCV≥ıÃΩ\\chap01 OpenCV≥ıÃΩ\\src\\creo NC µÒøÃª˙3018.mp4");
	while (ret)
	{
		cap >> frame;
		imshow("EXAMPLE02", frame);
		if (waitKey(32) > 0)
			break;
	}
	return 0;
}