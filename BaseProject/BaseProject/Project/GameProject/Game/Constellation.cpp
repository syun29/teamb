#include "Constellation.h"
#include "UI/Score.h"
int Constellation::starCnt[3] = { 0,0,0 };

Constellation::Constellation(const CVector3D& pos)
	:Task((int)ETaskPrio::UI, 0, eType_Constellation)
	
{
	m_img[0] = COPY_RESOURCE("Cons_Tri", CImage);
	m_img[0].ChangeAnimation(0);
	m_img[1] = COPY_RESOURCE("Cons_Quad", CImage);
	m_img[1].ChangeAnimation(0);
	m_img[2] = COPY_RESOURCE("Cons_Penta", CImage);
	m_img[2].ChangeAnimation(0);
}

Constellation::~Constellation()
{
}

void Constellation::Update()
{
	if (starCnt[0] == 3)
	{
		Score::AddScore(3000);
		starCnt[0]=4;
		SOUND("Constellation")->Play();
	}
	if (starCnt[1] == 4)
	{
		Score::AddScore(3000);
		starCnt[1] = 5;
		SOUND("Constellation")->Play();

	}
	if (starCnt[2] == 5)
	{
		Score::AddScore(3000);
		starCnt[2] = 6;
		SOUND("Constellation")->Play();

	}

}

void Constellation::Render()
{
	int sc0=starCnt[0];
	if (starCnt[0] == 4) {
		sc0 = 3;
	}
	int sc1 = starCnt[1];
	if (starCnt[1] == 5) {

		sc1 = 4;
	}
	int sc2 = starCnt[2];
	if (starCnt[2] == 6) {
		sc2 = 5;
	}
	m_img[0].SetPos(50,50);
	m_img[0].SetRect(300*sc0, 0, 300 + sc0*300, 300);
	m_img[0].SetSize(256, 256);
	m_img[0].Draw();
	m_img[1].SetPos(300,60);
	m_img[1].SetRect(300 * sc1, 0, 300 +sc1*300, 300);
	m_img[1].SetSize(256, 256);
	m_img[1].Draw();
	m_img[2].SetPos(530, 60);
	m_img[2].SetRect(300 * sc2, 0, 300 + sc2 * 300, 300);
	m_img[2].SetSize(256, 256);
	m_img[2].Draw();
}
