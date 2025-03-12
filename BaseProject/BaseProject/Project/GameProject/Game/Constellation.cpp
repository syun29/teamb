#include "Constellation.h"
#include "UI/Score.h"
int Constellation::starCnt[3] = { 0,0,0 };
Constellation::Constellation()
	:Task((int)ETaskPrio::UI, 0, eType_Constellation)
	
{

}

Constellation::~Constellation()
{
}

void Constellation::Update()
{
	if (starCnt[0] == 3)
	{
		Score::AddScore(3000);
	}
	if (starCnt[1] == 4)
	{
		Score::AddScore(3000);
	}
	if (starCnt[2] == 5)
	{
		Score::AddScore(3000);
	}

}

void Constellation::Render()
{
}
