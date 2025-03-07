#pragma once
#include"../System/ObjectBase.h"

class Field:public Task
{
private:
	int m_pos;
public:
	 Field(const CVector3D& pos);

	void Update();
	void Render();

	CImage m_backGround;
	CImage m_ground;
};