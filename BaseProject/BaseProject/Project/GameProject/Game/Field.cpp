#include "Field.h"
#include "../System/ObjectBase.h"
Field::Field(const CVector3D& pos)
	:Task((int)ETaskPrio::Field,0,eType_Field)
{
	m_backGround = COPY_RESOURCE("BackGround", CImage);
	m_ground = COPY_RESOURCE("Ground", CImage);
	m_backgroundscroll = 0;
}
void Field::Update()
{
	m_backgroundscroll += 0.2;
}

void Field::Render()
{
	float sc;
	sc = m_backgroundscroll;

	/*float b = 0;
	b = sc / (5500 / 2);
	m_backGround.SetAng(b);
	m_backGround.SetSize(1920*2,1080*2);
	m_backGround.SetPos(0,0);
	m_backGround.SetCenter(1920/2,1080/2);*/
	m_backGround.SetRect(sc, 0, sc + 1920, 1080);
	m_backGround.Draw();
	
	sc = ObjectBase::m_scroll.x;
	//m_ground.SetRect(sc, 0, sc + 720, 203);
	
	float a = 0;
	a = sc / (5500 / 2);
	m_ground.SetAng(a);
	m_ground.SetSize(5500, 5500);
	m_ground.SetPos(1920/2, 5500 /2+600);
	m_ground.SetCenter(5500 / 2, 5500 / 2);
	m_ground.Draw();
}
