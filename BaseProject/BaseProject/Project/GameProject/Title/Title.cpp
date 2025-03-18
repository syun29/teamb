#include "Title.h"
#include "Game/Game.h"
#include"Load.h"
Title::Title()
	:ObjectBase(eType_Title)
	,m_cnt(0)
{
	m_img = COPY_RESOURCE("Title", CImage);
	SOUND("Title")->Play();
}

void Title::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton10)) {
		Kill();
		new Load();
		SOUND("Title")->Stop();
	}
}

void Title::Render()
{
	m_img.Draw();
}
