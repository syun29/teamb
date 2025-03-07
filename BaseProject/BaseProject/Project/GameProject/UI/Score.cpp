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
	if (PUSH(CInput::eButton5))
	{
		score += 100;
	}
}

void Score::Render()
{
	scoreCnt = score;
	for (int i = 0; i < 6; i++,scoreCnt/10)
	{
		scoreGet = scoreCnt % 10;
		m_img.SetRect(scoreGet*102, 0, scoreGet * 102 + 102, 169);
		m_img.SetPos(1800 - 102*i, 100);
		m_img.Draw();
	}
}
