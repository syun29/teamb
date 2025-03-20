#include "Score.h"
int Score::s_score(0);
Score::Score(const CVector2D& p)
	:Task((int)ETaskPrio::UI, 0, eType_Score)
{
	m_img = COPY_RESOURCE("Score", CImage);
}

void Score::Update()
{
	
}

void Score::Render()
{
	int score = s_score;
	for (int i = 0; i < 6; i++,score/=10)
	{
		int s =score % 10;
		m_img.SetRect(102*s, 0,  102*s + 102, 169);
		m_img.SetSize(150, 110);
		m_img.SetPos(1700 - 102 * i, 10);
		m_img.Draw();

	}
}

void Score::AddScore(int ad)
{
	s_score += ad;
}

void Score::DownScore(int down)
{
	s_score -= down;
	if (s_score <= 0)
	{
		s_score = 0;
	}
}
