#pragma once
#include"../System/ObjectBase.h"

enum {
	eType_Tri,
	eType_Quad,
	eType_Penta,
	eType_Nomal
};
class SterManager :public ObjectBase
{
public:
//	int starRand;
	SterManager();
	~SterManager();
	void Update();
	int sterCnt;
};