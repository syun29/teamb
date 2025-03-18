#pragma once
#include"System/Task.h"

class Load :public Task {
	CImage m_img;

	int m_cnt;

public:
	Load();
	void Update();
	void Render();
};