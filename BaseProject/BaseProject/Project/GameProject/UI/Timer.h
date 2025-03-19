#pragma once
#include"../System/ObjectBase.h"

class Timer:public ObjectBase
{


public:
	static int getTime();
	static void resetTime();
	static void downTime(int down);
	//ゲージ用画像
	CImage m_img;
	//ゲージの幅
	int width = 700;
	//ゲージの高さ
	int height = 77;
	
	static int timeCnt;
	static int time_Max;
	Timer();
	void Update();
	void Render();

};