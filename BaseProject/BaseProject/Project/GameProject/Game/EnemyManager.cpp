#include "EnemyManager.h"
#include "Enemy.h"
EnemyManager::EnemyManager()
	:time(60*100)
	,enemyTimer(60*1)
	,ObjectBase(eType_Enemy)

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
			/*int enemyRand = rand() % 5;
			switch (enemyRand)
			{*/
				for (int i = 0; i < 1; i++) {
					CVector3D pos(Utility::Rand(1920.0f+m_scroll.x, 1920.f + m_scroll.x),
						Utility::Rand(0.0f, 100.0f),
						Utility::Rand(-50.0f, 150.0f));
					new Enemy(pos, CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				}
			/*case 0:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 100.0f, 0.0f), CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				break;
			case 1:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 230.0f , 50.0f), CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				break;
			case 2:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 300.0f , 0.0f), CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				break;
			case 3:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 400.0f, 50.0f), CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				break;
			case 4:
				new Enemy(
					CVector3D(1920.0f + m_scroll.x, 00.0f, 10.0f), CVector3D(64.0f, 128.0f, 40.0f), CVector3D(64.0f, 0.0f, 40.0f));
				break;*/
			
			enemyTimer = 60 * 3;
		}
	}
}
