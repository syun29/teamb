#pragma once
#include"../System/ObjectBase.h"


class SterManager :public ObjectBase
{
public:
	SterManager();
	~SterManager();

	void Update();
	int sterCnt;
};