#include "Timer.h"
#include "../System/TaskManager.h"
#include "Game/Result.h"
int Timer::timeCnt = 60 * 60;
int Timer::time_Max = 60 * 60;

int Timer::getTime()
{
	return timeCnt;
}

void Timer::resetTime()
{
	timeCnt = time_Max = 60 * 60;
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
		SOUND("Game")->Stop();
		timeCnt = 0;
		TaskManager::Instance()->DeleteAll();
		new Result();
		SOUND("Result")->Play();
	}
}

void Timer::Render()
{


	//�Q�[�W�w�i(��)
	m_img.SetPos(100, 10);
	m_img.SetSize(width, 77);
	m_img.SetRect(0, 0, width, 77);
	m_img.Draw();

	//�Q�[�W�̕�(��)
	int w = width * timeCnt/time_Max;
	m_img.SetPos(99, 6);
	m_img.SetSize(w, 77);
	m_img.SetRect(0, 77, w, 155);
	m_img.Draw();
}
