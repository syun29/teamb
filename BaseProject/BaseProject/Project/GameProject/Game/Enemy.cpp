#include "Enemy.h"
#include "UI/Score.h"
#define CHIP_SIZE 24 
#define CENTER_POS CVector3D(12.0f,12.0f) 
#define MOVE_SPEED_X 5.0f*2.0f 
#define MOVE_SPEED_Y 3.0f*2.0f 
#define MOVE_SPEED_Z 5.0f*2.0f 

TexAnimData Enemy::ANIM_DATA[1] =
{

	{
		new TexAnim[2]
	{
		{0,12},{1,12},
	},
	2
	}
};

Enemy::Enemy(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin, int types)
	:ObjectBase(pos, eType_Enemy)
	,type(types)
	,enemySwitch_y(true)
	,enemySwitch_z(true)
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
	if (type == 0) {
		m_pos.x -= MOVE_SPEED_X;
	}
	if (type == 1) {
		if (enemySwitch_y == true) {
			m_pos.x -= MOVE_SPEED_X;
			m_pos.y += MOVE_SPEED_Y;
		}
		if (m_pos.y >= 200) {
			enemySwitch_y = false;
		}
		if(enemySwitch_y==false) {
			m_pos.x -= MOVE_SPEED_X;
			m_pos.y -= MOVE_SPEED_Y;
		}
		if (m_pos.y <= 0) {
			enemySwitch_y = true;
		}
	}
	if (type == 2) {
		m_pos.x -= 10;
	}
	if (type == 3) {
		if (enemySwitch_z == true) {
			m_pos.x -= 2.5f;
			m_pos.z += 2.0f;
		}
		if (m_pos.z >= 200) {
			enemySwitch_z = false;
		}
		if (enemySwitch_z == false) {
			m_pos.x -= 2.5f;
			m_pos.z -= 2.0f;
		}
		if (m_pos.z <= -50) {
			enemySwitch_z = true;
		}
	}
	if (type == 4) {
		m_pos.x += 10.0f;
		m_img.SetFlipH(true);
	}
	m_img.UpdateAnimation();

}

void Enemy::Render()
{
	//m_img.SetPos(GetScreenPos(m_pos));

	m_img.SetPos(CalcScreenPos());
	CVector2D size = CalcScreenSize(CVector2D(128, 128));
	m_img.SetSize(size);
	m_img.SetCenter(size.x / 2, size.y);
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

