#pragma once
#include"../System/Task.h"
class Score :public Task
{
public:
	CImage m_img;
	
	static int s_score;
	Score(const CVector2D& p);
	void Update();
	void Render();
	static void AddScore(int ad);
	static void DownScore(int down);
};