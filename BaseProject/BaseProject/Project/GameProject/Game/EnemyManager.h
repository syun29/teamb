#pragma once
#include"../System/ObjectBase.h"


class EnemyManager:public ObjectBase
{
public:
	EnemyManager();
	~EnemyManager();
	int time;
	bool enemySwitch;
	int enemyCnt;
	int enemyTimer;
	void Update();
};