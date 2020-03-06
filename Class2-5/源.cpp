#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	float histgram[256];
	int Pixels[256];
	cv::Mat srcMat = imread("D:\\a\\b.jpg", 0);
	cv::Mat dispMat = imread("D:\\a\\h.png");
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int i = 0; i < 256; i++)
	{
		Pixels[i] = 0;
	}
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			Pixels[srcMat.at<uchar>(j, i)] += 1;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		histgram[i] = Pixels[i] * 1.0 / (height * width);
	}
	Point pt1[256];//ÖÕµã
	Point pt2[256];//Æðµã
	for (int j = 0; j < 256; j++)
	{
		pt1[j].x = 20 + 4 * j;
		pt1[j].y = histgram[j] * 13000;
		pt2[j].x = pt1[j].x;
		pt2[j].y = 0;
		line(dispMat, pt2[j], pt1[j], CV_RGB(255, 0, 0), 2, 8, 0);

	}
	cout << pt1[50].y << endl;
	imshow("pic", dispMat);
	waitKey(0);
	return 0;
}