```cpp
#define _CRT_SECURE_NO_WARNINGS//使用不安全检查
#include <iostream>
#include <ctype.h>
#include "opencv2/opencv.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

//#include "lfdemo.cpp";

//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp> 

using namespace std;
using namespace cv;

//main调用：
Mat g_src1 = imread("van.jpg");//载入图像
Mat g_src2 = imread("van2.jpg");//载入图像
Mat g_dst;
/*
1，图像腐蚀：用图像中的暗色部分"腐蚀"掉图像的高亮部分
2，均值滤波（模糊一幅图像）
TIPS:CX代表第几个参数
3,创建滑动条【createTrackbar函数】(C1：const string&【轨迹条的名字】,C2：const string&【窗体的名字（即对应namedWindow的窗口名）】,C3:int*【表示滑块的位置，滑块的初始位置就是它的值】,C4:int【滑块的MAX值】,  C5:指向回调函数的指针【当滑块位置改变，进行该函数，这个回调函数的类型必须为void XXX(int,void*)int是轨迹条的位置,void*是用户数数据（参数6）】如果回到是NULL指针，表示没有回调函数的使用，仅有第三个参数变化 C6:void*，也有默认值0，这个参数是永不传给回调函数的数据，用来处理轨迹条时间，如果第三个参数为全局变量的话，完全不用去管之歌参数)
   例子EG： createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
4、回调函数：一个通过函数指针调用的函数，如果我们把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，就称它为回调函数，回调函数在特定的时间或条件的时候被调用响应
5,【getTrackbarPos函数】：配合createTrackbarPos使用，获取当前轨迹条的位置int getTrackbarPos(C1:const string&【轨迹条的名字】,C2:const string&【轨迹条所属的窗体的名称】)
6,【setMouseCallback函数】：指定鼠标操作信息回调函数
setMouseCallback(C1:const string&【窗口的名字】C2:MouseCallback onMouse【指定每次鼠标事件发生后，被调用的函数指针，这个函数原型为7】C3:void* userdate=0【用户定义的传递到回调函数的参数】)
7,void Foo(C1:int event【enent是EVENT_+变量之一】,C2：int x【鼠标指针在图像坐标系的X】C3：int y【鼠标指针在图像坐标系的Y】C4:int flags【flags是EVENT_FLAG的组合】C5:void* param【param是用户定义到SetMouseCallBack中调用的参数，EG：EVENT_MOUSEMOVE为鼠标移动信息...】)
8，使用函数clone或是CopyTo来复制一副图像的矩阵
*/

//****************************************************
//定义lkdemo的变量：

//****************************************************

//****************************************************
//定义轨迹条的试用：
#define WINDOW_NAME1 "【线性混合实例】"//窗口标题的宏
const int g_nMaxAlphaValue = 100;//Alpha's MAX
int g_nAlphaValueSlider;//滑动条对应的变量
double g_dAlphaValue;
double g_dBettaValue;
//****************************************************

//****************************************************
//鼠标操作的使用
#define WINDOW_NAME2 "【程序窗口】"//窗口标题的宏
Rect g_rect;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);
//****************************************************


//****************************************************
//函数声明:
void Video_Canny();
void Video_jichu();
void Video_SavePic();
void lkdemo(int argc, char** argv);
void Trackbar();
void UseMouse();
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void subtract_TEST1();
//void lkdemo(argc, argv);

int main() {

	cout << "程序运行时，请勿关闭此窗口，否则程序将停止";
	//1，图像腐蚀：****************************************************
#pragma region MyRegion
	Mat src = imread("yz.jpg");//载入图像
	imshow("【原图】", src);//显示原图
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));//getStructuringElement函数返回一个指定形状和尺寸的结构元素（内核矩阵）。
	Mat dst1;
	erode(src, dst1, element);//进行图像腐蚀操作
	imshow("【图像腐蚀】", dst1);
#pragma endregion
	//************************************************

	//2，均值滤波：************************************************
	//进行均值滤波操作：
	Mat dst2;
	blur(src, dst2, Size(7, 7));
	imshow("【均值滤波】", dst2);
	//************************************************
	//3,边缘检测：
	Mat dst3, edge, gray;
	dst3.create(src.size(), src.type());//创建和src同类型和大小的矩阵(dst)
	cvtColor(src, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像

	blur(gray, edge, Size(3, 3));//使用3*3内核进行降噪
	imshow("【降噪】", edge);

	Canny(edge, edge, 3, 9, 3);//运行Canny算子
	imshow("【边缘检测】", edge);
	waitKey(0);
}
	//********************************************
	//TRY:lkdemo:
	//lkdemo(argc,argv);
	//Trackbar();
	//UseMouse();
	//subtract_TEST1();
	//Use(argc, argv);

//int Use();

void Video_jichu()
{
	//视频操作基础：
	VideoCapture cap;//实例化
	cap.open("1.avi");//参数填入0则调用摄像头采集视频
	//------>	VideoCapture capt("1.avi");
	while (1) //通过循坏将每一帧都显示出来
	{
		Mat frame;//定义Mat，存储每一帧的图像
		cap >> frame;//读取当前帧到Mat变量当中
		imshow("【视频】", frame);
	}
}
void Video_Canny()//调用摄像头并且用canny进行边缘检测
{
	VideoCapture capture(0);//从摄像头读取视频
	Mat edges;
	while (1)
	{
		Mat frame1;
		capture >> frame1;
		cvtColor(frame1, edges, CV_BGR2GRAY);//转化BGR彩色图为灰度图
		blur(edges, edges, Size(7, 7));//进行模糊，使用【3X3内核降噪（2x3+1=7）】
		Canny(edges, edges, 0, 30, 3);
		imshow("【AFTER CANNY】", edges);
		//if (waitKey(30>=0))
		//{
		//	break;//延迟30S
		//}
		waitKey(30);
	}
}
void Video_SavePic()
{
	VideoCapture cap3(0);
	Mat mat1;
	string a = "1";
	string houzhui = ".jpg";
	int num = 1;
	while (1)
	{
		a = num;
		Mat frame;
		cap3 >> frame;
		string filename = a + houzhui;
		imshow("【VIDEO】", frame);
		imwrite(filename, frame);
		num = num + 1;
		waitKey(30);
	}
}
void DrawRectangle(Mat& img, Rect box);

//****************************************************
//lkdemo的函数：
//
//void lkdemo(int argc, char** argv) {
//	VideoCapture cap;
//	TermCriteria termcrit(TermCriteria::COUNT | TermCriteria::EPS, 20, 0.03);
//	Size subPixWinSize(10, 10), winSize(31, 31);
//
//	const int MAX_COUNT = 500;
//	bool needToInit = false;
//	bool nightMode = false;
//
//	cv::CommandLineParser parser(argc, argv, "{@input|0|}");
//	string input = parser.get<string>("@input");
//
//	if (input.size() == 1 && isdigit(input[0]))
//		cap.open(input[0] - '0');
//	else
//		cap.open(input);
//
//	if (!cap.isOpened())
//	{
//		cout << "Could not initialize capturing...\n";
//	}
//
//	namedWindow("LK Demo", 1);
//	setMouseCallback("LK Demo", onMouse, 0);
//
//	Mat gray, prevGray, image, frame;
//	vector<Point2f> points[2];
//
//	for (;;)
//	{
//		cap >> frame;
//		if (frame.empty())
//			break;
//
//		frame.copyTo(image);
//		cvtColor(image, gray, COLOR_BGR2GRAY);
//
//		if (nightMode)
//			image = Scalar::all(0);
//
//		if (needToInit)
//		{
//			// automatic initialization
//			goodFeaturesToTrack(gray, points[1], MAX_COUNT, 0.01, 10, Mat(), 3, 3, 0, 0.04);
//			cornerSubPix(gray, points[1], subPixWinSize, Size(-1, -1), termcrit);
//			addRemovePt = false;
//		}
//		else if (!points[0].empty())
//		{
//			vector<uchar> status;
//			vector<float> err;
//			if (prevGray.empty())
//				gray.copyTo(prevGray);
//			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,
//				3, termcrit, 0, 0.001);
//			size_t i, k;
//			for (i = k = 0; i < points[1].size(); i++)
//			{
//				if (addRemovePt)
//				{
//					if (norm(point - points[1][i]) <= 5)
//					{
//						addRemovePt = false;
//						continue;
//					}
//				}
//
//				if (!status[i])
//					continue;
//
//				points[1][k++] = points[1][i];
//				circle(image, points[1][i], 3, Scalar(0, 255, 0), -1, 8);
//			}
//			points[1].resize(k);
//		}
//
//		if (addRemovePt && points[1].size() < (size_t)MAX_COUNT)
//		{
//			vector<Point2f> tmp;
//			tmp.push_back(point);
//			cornerSubPix(gray, tmp, winSize, Size(-1, -1), termcrit);
//			points[1].push_back(tmp[0]);
//			addRemovePt = false;
//		}
//
//		needToInit = false;
//		imshow("LK Demo", image);
//
//		char c = (char)waitKey(10);
//		if (c == 27)
//			break;
//		switch (c)
//		{
//		case 'r':
//			needToInit = true;
//			break;
//		case 'c':
//			points[0].clear();
//			points[1].clear();
//			break;
//		case 'n':
//			nightMode = !nightMode;
//			break;
//		}
//
//		std::swap(points[1], points[0]);
//		cv::swap(prevGray, gray);
//	}
//}
////****************************************************

//****************************************************
//【on_Trackbar函数】//回调函数
void on_Trackbar(int, void*)
{
	//求当前alpha值相对的最大值的比例：
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	//bete值为1-
	g_dBettaValue = (1.0 - g_dAlphaValue);
	//根据alpha和beta进行线性混合：
	addWeighted(g_src1, g_dAlphaValue, g_src2, g_dBettaValue, 0.0, g_dst);
	imshow(WINDOW_NAME1, g_dst);
}
//【Trackbar函数】//创建使用滑动条
void Trackbar()
{   //滑动条初始值为70
	g_nAlphaValueSlider = 70;
	//创建窗体
	namedWindow(WINDOW_NAME1, 1);
	//在创建的窗体中创建一个滑动条：
	char TrackbarName[50];
	sprintf(TrackbarName, "透明值%d", g_nMaxAlphaValue);
	createTrackbar(TrackbarName, WINDOW_NAME1, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	//结果在回调函数中显示：
	on_Trackbar(g_nAlphaValueSlider, 0);
	//获取当前轨迹条的位置
	int t_a = getTrackbarPos(TrackbarName, WINDOW_NAME1);
	cout.put(t_a);
}
//****************************************************

//****************************************************
//【UseMouse函数】
void UseMouse()
{   //准备参数
	g_rect = Rect(-1, -1, 0, 0);
	Mat srcImge(600, 800, CV_8UC3), tempImage;//???
	srcImge.copyTo(tempImage);
	g_rect = Rect(-1, -1, 0, 0);
	srcImge = Scalar::all(0);//???
	//设置鼠标操作回调函数
	namedWindow(WINDOW_NAME2);
	setMouseCallback(WINDOW_NAME2, on_MouseHandle, (void*)&srcImge);
	//当进行绘制的标识符为TRUE，绘制
	while (true) {
		srcImge.copyTo(tempImage);//复制原图到临时变量
		if (g_bDrawingBox)
		{
			DrawRectangle(tempImage, g_rect);//绘制
			imshow(WINDOW_NAME2, tempImage);
		}
		if (waitKey(10)==27)//按下ESC键
		{
			break;
		}
	}
}
//【on_MouseHandle函数:】鼠标回调函数，根据不同的鼠标事件进行不同的操作
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*) param;
	switch (event)
	{
		//鼠标移动信息：
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)//如果是否进行绘制的标识符为true，则记录下长和宽到RECT类型的变量当中
		{
			g_rect.width = x - g_rect.x;
			g_rect.height = y - g_rect.y;

		}
	}
	break;
	//左键按下消息：
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rect = Rect(x, y, 0, 0);//记录起始点
	}
	break;
	//左键抬起信息：
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;
		//对宽和高小于0的处理：
		if (g_rect.width < 0)
		{
			g_rect.x += g_rect.width;
			g_rect.width *= -1;
		}
		if (g_rect.height < 0)
		{
			g_rect.y += g_rect.height;
			g_rect.height *= -1;
		}
		//调用函数进行绘制：
		DrawRectangle(image, g_rect);
	}
	break;
	}

}
//【DrawRectangle函数】自定义的矩形绘制函数：
void DrawRectangle(Mat& img, Rect box) {
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255)), g_rng.uniform(0, 255), g_rng.uniform(0, 255));//随机颜色
}
//****************************************************
void book_4_1_5() 
{
	//4.15OpenCV中的格式化输出方法
	Mat r = Mat(10, 3, CV_8UC3);
	randu(r, Scalar::all(0), Scalar::all(255));
		//用randu函数产生的随机值来填充矩阵，同时要给一个上下限来确保随机值在期望之中
}
void book_4_1_6()
{
	//4.16其他常用数据结构:
	//定义二维点：
	Point2f p2(6, 2);
	//定义三维点：
	Point3f p3(8, 3, 0);
	//基于Mat 的vector:
	vector<float> v;
	v.push_back(3);
	//定义输出std::vector点：
	vector<Point2f> points(20);
	for (size_t i = 0; i < points.size(); i++)
	{
		points[i] = Point2f((float) (i * 5), (float)(i % 7));
	}
}
void subtract_TEST1()
{
	Mat src1 = imread("5.jpg");
	Mat src2 = imread("6.jpg");
	//Mat src3 = imread("3.jpg");
	//Mat src4 = imread("4.jpg");
	//Mat gray;
	//Mat dst3, edge, gray;
	//dst3.create(src1.size(), src1.type());//创建和src同类型和大小的矩阵(dst)
	//cvtColor(src1, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像
	//Canny(edge, edge, 3, 9, 3);//运行Canny算子
	//imshow("【边缘检测】", edge);
	//cvtColor(src1, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像
	//cvtColor(src2, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像
	//cvtColor(src3, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像
	//cvtColor(src4, gray, COLOR_BGR2GRAY);//将原图片转为灰度图像

	Mat result;
	//subtract(src1, src2, result);
	//imshow("image BY subtract()", result);
	absdiff(src1, src2, result);
	imshow("image BY 1,2", result);
	//absdiff(src3, src4, result);
	//imshow("image BY 3,4", result);
	//absdiff(src1, src4, result);
	//imshow("image BY 1,4", result);
	waitKey();
}

```