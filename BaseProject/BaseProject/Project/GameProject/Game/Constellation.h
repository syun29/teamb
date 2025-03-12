#pragma once
#include"System/Task.h"
class Constellation :public Task 
{
public:
	Constellation();
	~Constellation();
	void Update();
	void Render();
	static int starCnt[3];
	
};