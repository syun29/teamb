#pragma once
#include"../System/StarBase.h"
class Score :public StarBase 
{
public:
	CImage m_img;
	
	int scoreCnt;
	int scoreGet;
	Score(const CVector2D& p);
	void Update();
	void Render();
};