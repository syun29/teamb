#include "Field.h"

Field::Field(const CVector3D& pos)
	:ObjectBase()
{
	m_backGround = COPY_RESOURCE("BackGround", CImage);
	m_ground = COPY_RESOURCE("Ground", CImage);
}
void Field::Update()
{

}

void Field::Render()
{
	float sc;
	m_backGround.Draw();

	sc = m_scroll.x/2;
	m_ground.SetRect(sc, 0, sc + 720, 203);
	m_ground.Draw();
	m_ground.SetSize(720 * 3, 203 * 3);
	m_ground.SetPos(0, 450);
}
