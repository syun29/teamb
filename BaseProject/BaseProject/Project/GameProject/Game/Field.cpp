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
	m_backgroundscroll += 0.5;
}

void Field::Render()
{
	float sc;
	sc = m_backgroundscroll;
	m_backGround.SetRect(sc, 0, sc + 1920, 1080);
	m_backGround.Draw();
	
	sc = ObjectBase::m_scroll.x/3;
	m_ground.SetRect(sc, 0, sc + 720, 203);
	m_ground.Draw();
	m_ground.SetSize(720 * 3, 203 * 3);
	m_ground.SetPos(0, 450);
}
