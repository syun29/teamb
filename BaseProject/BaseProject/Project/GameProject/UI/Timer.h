#pragma once
#include"../System/ObjectBase.h"

class Timer:public ObjectBase
{


public:
	static int getTime();
	static void resetTime();
	static void downTime(int down);
	//�Q�[�W�p�摜
	CImage m_img;
	//�Q�[�W�̕�
	int width = 700;
	//�Q�[�W�̍���
	int height = 77;
	
	static int timeCnt;
	static int time_Max;
	Timer();
	void Update();
	void Render();

};