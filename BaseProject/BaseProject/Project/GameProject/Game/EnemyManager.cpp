#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager()
	:time(60 * 60)
	, enemyTimer(60 * 3)
	, Task((int)ETaskPrio::EnemyManager, 0, eType_Enemy)
	,enemySwitch(true)
	,enemyCnt(0)

{

	
}


EnemyManager::~EnemyManager()
{

}

void EnemyManager::Update()
{
	time--;
	if (time % (10*60) == 0) {
		
		enemySwitch=false;
		enemyCnt++;
	}
	
	enemyTimer--;
	if (time >= 0) {
		if (enemySwitch == false) {
			if (enemyCnt == 1) {
				for (int i = 0; i < 5; i++) {
					new Enemy(CVector3D(1920.0f + ObjectBase::m_scroll.x, 0.0f, -50 + 50 * i), CVector3D(64.0f, 100.0f, 20.0f), CVector3D(64.0f, -30.0f, 20.0f), 0);
				}
				enemySwitch = true;
			}
			if (enemyCnt == 2) {
				for (int i = 0; i < 5; i++) {
					new Enemy(CVector3D(0.0f + ObjectBase::m_scroll.x, 0.0f, -50 + 50 * i), CVector3D(64.0f, 100.0f, 20.0f), CVector3D(64.0f, -30.0f, 20.0f), 5);
				}
				enemySwitch = true;
			}
			if (enemyCnt == 3) {
				for (int i = 0; i < 5; i++) {
					new Enemy(CVector3D(1920.0f + ObjectBase::m_scroll.x, 0.0f, -150 + 100 * i), CVector3D(64.0f, 100.0f, 20.0f), CVector3D(64.0f, -30.0f, 20.0f), 4);
					enemySwitch = true;
				}
			}
			if (enemyCnt >= 4) {
				enemySwitch = true;
			}
		}
		if (enemyTimer < 0) {
			if (enemySwitch == true) {
				int newRand = rand() % 4;

				CVector3D pos(Utility::Rand(1920.0f + ObjectBase::m_scroll.x, 1920.f + ObjectBase::m_scroll.x),
					Utility::Rand(0.0f, 350.0f),
					Utility::Rand(-50.0f, 200.0f));
				int enemyType = rand() % 4;
				new Enemy(pos, CVector3D(64.0f, 100.0f, 20.0f), CVector3D(64.0f, -30.0f, 20.0f), enemyType);



				enemyTimer = 60 * 2;
			}
		}
		
	}
}
