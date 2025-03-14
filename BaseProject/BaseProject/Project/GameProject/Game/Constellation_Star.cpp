#include "Constellation_Star.h"
#include "UI/Score.h"
#include "Constellation.h"
Constellation_Star::Constellation_Star(const CVector3D& pos,CVector3D& cubeMax, CVector3D& cubeMin, int kinds)
	:kind(kinds)
{
	char constellaion_ster[3] [6] = {
	 "tri",
	 "quad",
	 "penta"

	};
	
	m_img=COPY_RESOURCE(constellaion_ster[kinds], CImage);
	m_img.SetSize(100, 100);
	m_pos = pos;
	m_cubeMax = cubeMax;
	m_cubeMin = cubeMin;

	
}

Constellation_Star::~Constellation_Star()
{
}

void Constellation_Star::Update()
{
	
}

void Constellation_Star::Render()
{
	RenderShadow();
	m_img.SetPos(CalcScreenPos());
	CVector2D size = CalcScreenSize(CVector2D(137, 137));
	m_img.SetSize(size);
	m_img.SetCenter(size.x / 2, size.y*1.6);

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
