#pragma once
#include "System/Task.h"
class Effect :public Task 
{
public:
	Effect(const char* name, const CVector3D& pos);
	~Effect();
	static TexAnimData ANIM_DATA[];


	
	CImage m_img;
	CVector3D m_pos;
	void Update();
	void Render();
};