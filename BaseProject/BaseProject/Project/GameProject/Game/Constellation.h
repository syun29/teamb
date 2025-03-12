#pragma once
#include"System/Task.h"
class Constellation :public Task 
{
public:
	Constellation(const CVector3D& pos);
	~Constellation();
	void Update();
	void Render();
	CImage m_img[3];
	static int starCnt[3];
	
};