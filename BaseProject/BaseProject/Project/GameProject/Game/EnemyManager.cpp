#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager()
	:time(60 * 60)
	, enemyTimer(60 * 0.3)
	, ObjectBase(eType_Enemy)
	

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
			int newRand = rand() % 4;

			CVector3D pos(Utility::Rand(1920.0f + m_scroll.x, 1920.f + m_scroll.x),
				Utility::Rand(0.0f, 350.0f),
				Utility::Rand(-50.0f, 200.0f));
			int enemyType = rand() % 4;
			new Enemy(pos, CVector3D(64.0f, 128.0f, 20.0f), CVector3D(64.0f, 0.0f, 20.0f), enemyType);

		
			
			enemyTimer = 60 * 0.3;
		}
	}
}
