#include "Timer.h"
int Timer::timeCnt = 60 * 120;
int Timer::time_Max = 60 * 120;

int Timer::getTime()
{
	return timeCnt;
}

void Timer::resetTime()
{
	timeCnt = time_Max = 60 * 120;
}

Timer::Timer()
	:ObjectBase(eType_Timer)
{
	m_img = COPY_RESOURCE("Timer", CImage);
}

void Timer::Update()
{
	timeCnt--;
	if (timeCnt < 0)
	{
		timeCnt = 0;
	}
}

void Timer::Render()
{


	//ƒQ[ƒW”wŒi(Ô)
	m_img.SetPos(100, 100);
	m_img.SetSize(width, 77);
	m_img.SetRect(0, 0, width, 77);
	m_img.Draw();

	//ƒQ[ƒW‚Ì•(—Î)
	int w = width * timeCnt/time_Max;
	m_img.SetPos(99, 96);
	m_img.SetSize(w, 77);
	m_img.SetRect(0, 77, w, 155);
	m_img.Draw();
}
