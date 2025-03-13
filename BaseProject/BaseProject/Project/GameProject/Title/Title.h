#pragma once
#include"System/ObjectBase.h"

class Title :public ObjectBase {
	CImage m_img;

	int m_cnt;

public:
	Title();
	void Update();
	void Render();
};