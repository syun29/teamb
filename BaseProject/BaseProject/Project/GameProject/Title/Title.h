#pragma once
#include"System/Task.h"

class Title :public Task {
	CImage m_img;
	int m_cnt;
	int m_moveCnt;
public:
	Title();
	void Update();
	void Render();
};