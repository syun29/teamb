#include "Nomal.h"
#include"UI/Score.h"
#include "UI/Effect.h"
#define CHIP_SIZE 137
#define CENTER_POS CVector3D(68.0f,135.0f)

//星のアニメーションデータ
TexAnimData Nomal::ANIM_DATA[1] =
{
	{
		new TexAnim[4]
	{
		{0,12},{1,12},{2,12},{3,12},
	},4

	}
};

//コンストラクタ
Nomal::Nomal(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin)
	:ObjectBase(pos, eType_Star)
{
	//画像読み込み
	m_img = COPY_RESOURCE("Nomal", CImage);
	m_pos = pos;
	m_img.ChangeAnimation(0);
	m_cnt = 0;
	m_cubeMax = CVector3D(30, 30, 30);
	m_cubeMin= CVector3D(30, 30, 30);
	m_cubeMax = cubeMax;
	m_cubeMin = cubeMin;
}
Nomal::~Nomal()
{
}

void Nomal::Update()
{
	m_img.UpdateAnimation();
}

void Nomal::Render()
{
	RenderShadow();
	m_img.SetPos(CalcScreenPos());
	CVector2D size = CalcScreenSize(CVector2D(200, 200));
	m_img.SetSize(size);
	m_img.SetCenter(size.x / 2, size.y);

	m_img.Draw();
	RenderCubu();
}

void Nomal::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player: {
		if (ObjectBase::CollisionCube(this, dynamic_cast<ObjectBase*>(b))) 
		{
			Kill();
			Score::AddScore(100);
			new Effect("Effect_Get", CVector3D(m_pos));

		}
	}
	}
}
