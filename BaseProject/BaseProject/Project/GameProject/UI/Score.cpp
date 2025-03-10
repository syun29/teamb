#include "Score.h"

Score::Score(const CVector2D& p)
	:scoreCnt(0)
	,scoreGet(0)
{
	m_img = COPY_RESOURCE("Score", CImage);
	m_img.SetSize(150, 110);
}

void Score::Update()
{
	
}

void Score::Render()
{
	scoreCnt = score;
	for (int i = 0; i < 6; i++,scoreCnt/10)
	{
		scoreGet = scoreCnt;
		m_img.SetRect(scoreGet*102, 0, scoreGet * 102 + 102, 169);
		m_img.SetPos(1900 - 102*i, 100);
		
	}
	m_img.Draw();
}
