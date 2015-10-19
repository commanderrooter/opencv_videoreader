// video_okuma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, _TCHAR* argv[])
{
				
					VideoCapture vid("C:\\Users\\RSK\\Desktop\\videolar\\1.mp4");
					if (!vid.isOpened()){
						cout << "Video acılamadı"<<endl;
						return -1;
										}
					vid.set(CV_CAP_PROP_POS_MSEC, 3000);
					//vid.set(CV_CAP_PROP_FRAME_HEIGHT, 40);
					//vid.set(CV_CAP_PROP_FRAME_WIDTH, 80);
					
					double fps = vid.get(CV_CAP_PROP_FPS);
					cout << "FramePerSecond" << fps << endl;
					
					//namedWindow("Bu Video ",1);
					
					resizeWindow("Bu Video", 1366, 768);
					
					while (1)
					{
						Mat res;
						bool bbasari = vid.read(res);
						if (!bbasari){

							cout << "Yeni Frame Okunamadı ";
							break;
						}
						resizeWindow("Bu Video", 1366, 768);
						imshow("Bu Video", res);


						if (waitKey(30) == 27)
						{
							cout << "Esc ile cıkıs yaptınız ";

							break;
						}
					}
					system("pause");
					return 0; 
}

