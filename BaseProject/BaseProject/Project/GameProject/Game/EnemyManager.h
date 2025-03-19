#pragma once
#include"../System/Task.h"


class EnemyManager:public Task
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