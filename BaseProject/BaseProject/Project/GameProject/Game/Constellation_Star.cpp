#include "Constellation_Star.h"
#include "UI/Score.h"
#include "Constellation.h"
#include"UI/Effect.h"
TexAnimData Constellation_Star::ANIM_DATA[3] =
{
	
	{
		new TexAnim[3]
	{
		{0,12*2},{1,12*2},{2,12*2}
		},
		3
		},
	{
		new TexAnim[3]
	{
		{0,12},{1,12},{2,12}
		},
		3
		},
	{
		new TexAnim[3]
	{
		{0,12},{1,12},{2,12}
		},
		3
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
	//m_img.SetRect(0, 128, 128, 128*2);
	m_img.SetRect(128*2, 128, 128*3, 128 * 2);
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
			new Effect("Effect_Get", CVector3D(m_pos));
			for (int i = 0; i < 10; i++) {
				CVector3D v(Utility::Rand(-5.0f, 5.0f),
					Utility::Rand(8.0f, .10f),
					Utility::Rand(0.0f, 0.0f));
				new PerticleEffect("MiniStar", CVector3D(m_pos), v, CVector2D(50, 50));
			}
		}
	}
	}
}
