#include "Constellation.h"
#include "UI/Score.h"
int Constellation::starCnt[3] = { 0,0,0 };
Constellation::Constellation(const CVector3D& pos)
	:Task((int)ETaskPrio::UI, 0, eType_Constellation)
	
{
	m_img[0] = COPY_RESOURCE("Cons_Tri", CImage);
	m_img[0].ChangeAnimation(0);
	m_img[0].SetSize(64 * 2, 64 * 2);
	m_img[1] = COPY_RESOURCE("Cons_Quad", CImage);
	m_img[1].ChangeAnimation(0);
	m_img[1].SetSize(64 * 2, 64 * 2);
	m_img[2] = COPY_RESOURCE("Cons_Penta", CImage);
	m_img[2].ChangeAnimation(0);
	m_img[2].SetSize(64 * 2, 64 * 2);
}

Constellation::~Constellation()
{
}

void Constellation::Update()
{
	if (starCnt[0] == 3)
	{
		Score::AddScore(3000);
		starCnt[0] = 0;
	}
	if (starCnt[1] == 4)
	{
		Score::AddScore(3000);
		starCnt[1] = 0;

	}
	if (starCnt[2] == 5)
	{
		Score::AddScore(3000);
		starCnt[2] = 0;

	}

}

void Constellation::Render()
{
	m_img[0].SetPos(150,150);
	m_img[0].Draw();
	m_img[1].SetPos(150*2, 150);
	m_img[1].Draw();
	m_img[2].SetPos(150*3, 150);
	m_img[2].Draw();
}
