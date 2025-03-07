#include "Constellation_Star.h"

Constellation_Star::Constellation_Star(const CVector3D& pos,int kinds)
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
	/*m_tri = COPY_RESOURCE("TRI", CImage);
	m_tri.ChangeAnimation(0);
	m_tri.SetSize(64 * 2, 64 * 2);

	m_quad = COPY_RESOURCE("QUAD", CImage);
	m_quad.ChangeAnimation(0);
	m_quad.SetSize(64 * 2, 64 * 2);

	m_penta = COPY_RESOURCE("PENTA", CImage);
	m_penta.ChangeAnimation(0);
	m_penta.SetSize(64 * 2, 64 * 2);*/

	
}

Constellation_Star::~Constellation_Star()
{
}

void Constellation_Star::Update()
{
	if (PUSH(CInput::eButton2))
	{
		score += 100;
	}
}

void Constellation_Star::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
	/*m_tri.SetPos(CalcScreenPos());
	m_tri.Draw();
	m_quad.SetPos(CalcScreenPos());
	m_quad.Draw();
	m_penta.SetPos(CalcScreenPos());
	m_penta.Draw();*/
}
