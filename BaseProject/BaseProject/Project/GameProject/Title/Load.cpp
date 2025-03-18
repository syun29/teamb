#include "Load.h"
#include"Game/Game.h"
Load::Load()
	:Task((int)ETaskPrio::UI, 0, eType_Load)
	,m_cnt(0)
{
	m_img = COPY_RESOURCE("Load", CImage);
}

void Load::Update()
{
	if (m_cnt++ > 60 * 5) {
		Kill();
		new Game();
		SOUND("Game")->Play();
	}
	
}

void Load::Render()
{
	m_img.Draw();

}
