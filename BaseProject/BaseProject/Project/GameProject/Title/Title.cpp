#include "Title.h"
#include "Game/Game.h"
Title::Title()
	:ObjectBase(eType_Title)
{
	m_img = COPY_RESOURCE("Title", CImage);
}

void Title::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton10)) {
		Kill();
		new Game();
	}
}

void Title::Render()
{
	m_img.Draw();
}
