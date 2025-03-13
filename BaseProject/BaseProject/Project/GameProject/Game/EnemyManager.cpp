#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager()
	:time(60*100)
	,enemyTimer(60*3)
	,ObjectBase(eType_Enemy)

{

	
}


EnemyManager::~EnemyManager()
{

}

void EnemyManager::Update()
{
	/*time--;
	enemyTimer--;
	if (time >= 0) {
		if (enemyTimer < 0) {
			int enemyRand = rand() % 3;
			switch (enemyRand)
			{
			case 0:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 100.0f, 0.0f), CVector3D(20.0f, 20.0f, 20.0f));
				break;
			case 1:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 230.0f , 50.0f), CVector3D(20.0f, 20.0f, 20.0f));
				break;
			case 2:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 300.0f , 0.0f), CVector3D(20.0f, 20.0f, 20.0f));
				break;
			}
			enemyTimer = 60 * 3;
		}
	}*/
}
