#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager()
	:time(60*100)
	,enemyTimer(60*3)
{

	
}


EnemyManager::~EnemyManager()
{

}

void EnemyManager::Update()
{
	time--;
	enemyTimer--;
	if (time >= 0) {
		if (enemyTimer < 0) {
			int enemyRand = rand() % 3;
			switch (enemyRand)
			{
			case 0:
				new Enemy(
					CVector3D(1500.0f, 100.0f, 0.0f));
				break;
			case 1:
				new Enemy(
					CVector3D(1500.0f, 230.0f, 50.0f));
				break;
			case 2:
				new Enemy(
					CVector3D(1500.0f, 300.0f, 0.0f));
				break;
			}
			enemyTimer = 60 * 3;
		}
	}
}
