//跳转
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
	g_cap.set(CAP_PROP_POS_FRAMES, pos); // CAP_PROP_POS_FRAMES:从0开始索引帧，帧位置。
	if (!g_dontset)
	{
		g_run = 1;
	}
	g_dontset = 0;
}
int main()
{
	namedWindow("视频跳转", WINDOW_NORMAL);
	bool ret = g_cap.open("D:\\Local_Workstation\\sys_File\\GitHub_worksation\\Study_Notes\\OpenCV_Notes\\chap01 OpenCV初探\\chap01 OpenCV初探\\src\\creo NC 雕刻机3018.mp4");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "该视频有" << frames << "帧，每一帧长和宽为：" << tmpw << "X" << tmph;
	createTrackbar("position", "视频跳转", &g_slider_position, frames, onTrackbarSlider);

	Mat frame;
	while (ret)
	{
		if (g_run != 0)
		{
			g_cap >> frame;
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			setTrackbarPos("position", "视频跳转", current_pos);
			imshow("视频跳转", frame);
			g_run -= -1;
		}
		char keyboard = (char)waitKey(10);
		if (keyboard == 's')
		{
			g_run = 1;
			cout << "单步模式，run = " << g_run << endl;
		}
		if (keyboard == 'r')
		{
			g_run = -1;
			cout << "连播模式，run = " << g_run << endl;
		}
		if (keyboard == 27)
		{
			break;
		}
		
	}

	return 0;
}