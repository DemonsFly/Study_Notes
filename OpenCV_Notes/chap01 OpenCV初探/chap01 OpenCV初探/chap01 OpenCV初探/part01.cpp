//��ʾͼƬ
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:\\Local_Workstation\\sys_File\\GitHub_worksation\\Study_Notes\\OpenCV_Notes\\chap01 OpenCV��̽\\chap01 OpenCV��̽\\src\\logo.png");
	if (src.empty())
	{
		cout << "��ȡʧ��" << endl;

	}
	else
	{
		namedWindow("EXAMPLE", WINDOW_AUTOSIZE);	// ��ʡ��
		imshow("EXAMPLE", src);
	}
	waitKey(0);	//�ȴ���������
	destroyWindow("EXAMPLE");	//��ʡ��
	return 0;
}