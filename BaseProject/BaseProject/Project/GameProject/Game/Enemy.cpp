#include "Enemy.h"

#define CHIP_SIZE 24 
#define CENTER_POS CVector3D(12.0f,12.0f) 
#define MOVE_SPEED_X 3.0f 
#define MOVE_SPEED_Y 3.0f 

Enemy::Enemy(const CVector3D& pos)
	:ObjectBase(pos,eType_Enemy)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(64*2, 64*2);
	m_rad = 50;

	
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	m_pos.x -= 5;
	

}

void Enemy::Render()
{
	//m_img.SetPos(GetScreenPos(m_pos));

	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
	//mp_image->Draw();

}

void Enemy::Collision(Task*b)
{
	switch (b->m_type) {
	case eType_Player: {
		CVector3D v = b->m_pos - m_pos;
		if (abs(v.x) < 32) {

		printf("“–‚½‚Á‚½");
		}
	}


	}
}

