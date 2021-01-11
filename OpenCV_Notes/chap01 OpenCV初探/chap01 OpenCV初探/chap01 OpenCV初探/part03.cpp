//��ת
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
VideoCapture g_cap;

void onTrackbarSlider(int pos, void*)
{
	g_cap.set(CAP_PROP_POS_FRAMES, pos); // CAP_PROP_POS_FRAMES:��0��ʼ����֡��֡λ�á�
	if (!g_dontset)
	{
		g_run = 1;
	}
	g_dontset = 0;
}
int main()
{
	namedWindow("��Ƶ��ת", WINDOW_NORMAL);
	bool ret = g_cap.open("D:\\Local_Workstation\\sys_File\\GitHub_worksation\\Study_Notes\\OpenCV_Notes\\chap01 OpenCV��̽\\chap01 OpenCV��̽\\src\\creo NC ��̻�3018.mp4");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "����Ƶ��" << frames << "֡��ÿһ֡���Ϳ�Ϊ��" << tmpw << "X" << tmph;
	createTrackbar("position", "��Ƶ��ת", &g_slider_position, frames, onTrackbarSlider);

	Mat frame;
	while (ret)
	{
		if (g_run != 0)
		{
			g_cap >> frame;
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			setTrackbarPos("position", "��Ƶ��ת", current_pos);
			imshow("��Ƶ��ת", frame);
			g_run -= -1;
		}
		char keyboard = (char)waitKey(10);
		if (keyboard == 's')
		{
			g_run = 1;
			cout << "����ģʽ��run = " << g_run << endl;
		}
		if (keyboard == 'r')
		{
			g_run = -1;
			cout << "����ģʽ��run = " << g_run << endl;
		}
		if (keyboard == 27)
		{
			break;
		}
		
	}

	return 0;
}