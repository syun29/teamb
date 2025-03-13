#include "Enemy.h"
#include "UI/Score.h"
#define CHIP_SIZE 24 
#define CENTER_POS CVector3D(12.0f,12.0f) 
#define MOVE_SPEED_X 5.0f 
#define MOVE_SPEED_Y 3.0f 

Enemy::Enemy(const CVector3D& pos,CVector3D& cubeMax, CVector3D& cubeMin)
	:ObjectBase(pos,eType_Enemy)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	m_cubeMax = cubeMax;
	m_cubeMin = cubeMin;

}

Enemy::~Enemy()
{
}

void Enemy::Update()
{	
	m_pos.x -= MOVE_SPEED_X;	
}

void Enemy::Render()
{
	//m_img.SetPos(GetScreenPos(m_pos));

	m_img.SetPos(CalcScreenPos());
	m_img.SetCenter(64, 128);
	m_img.SetSize(128, 128);
	m_img.Draw();
	ObjectBase::RenderShadow();
	RenderCubu();
	//mp_image->Draw();

}

void Enemy::Collision(Task*b)
{
	switch (b->m_type) {
	case eType_Player: {
		if (ObjectBase::CollisionCube(this, dynamic_cast<ObjectBase*>(b))) 
		{
			Kill();
			Score::DownScore(500);
			
		}
		
	}


	}
}

