#pragma once
#include"../System/ObjectBase.h"


class EnemyManager:public ObjectBase
{
public:
	EnemyManager();
	~EnemyManager();

	int time;
	int enemyTimer;
	void Update();
};