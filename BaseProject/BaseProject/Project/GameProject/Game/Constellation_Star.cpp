#include "Constellation_Star.h"
#include "UI/Score.h"
#include "Constellation.h"
TexAnimData Constellation_Star::ANIM_DATA[4] =
{
	//待機アニメーション
	{
		new TexAnim[3]
	{
		{0,12},{1,12},
		},
		2
		},
};

Constellation_Star::Constellation_Star(const CVector3D& pos,CVector3D& cubeMax, CVector3D& cubeMin, int kinds)
	:ObjectBase(pos, eType_Star)

	,kind(kinds)
{
	char constellaion_ster[3] [6] = {
	 "tri",
	 "quad",
	 "penta"

	};
	
	m_img=COPY_RESOURCE(constellaion_ster[kinds], CImage);
	m_pos = pos;
	m_cubeMax = cubeMax;
	m_cubeMin = cubeMin;
	m_img.ChangeAnimation(0);
	
}

Constellation_Star::~Constellation_Star()
{
}

void Constellation_Star::Update()
{
	m_img.UpdateAnimation();
}

void Constellation_Star::Render()
{
	RenderShadow();
	m_img.SetPos(CalcScreenPos());
	CVector2D size = CalcScreenSize(CVector2D(100, 100));
	m_img.SetSize(size);
	m_img.SetCenter(size.x / 2, size.y);
	m_img.SetRect(64, 128, 64, 0);
	m_img.Draw();
	RenderCubu();
}

void Constellation_Star::Collision(Task* b)
{
	switch (b->m_type) 
	{
	case eType_Player: {
		if (ObjectBase::CollisionCube(this, dynamic_cast<ObjectBase*>(b)))
		{
			
			Kill();
			Constellation::starCnt[kind]++;
			Score::AddScore(100);
		}
	}
	}
}
