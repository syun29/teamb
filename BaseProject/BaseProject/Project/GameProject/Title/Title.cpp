#include "Title.h"
#include "Game/Game.h"
#include"Load.h"
#include"UI/Effect.h"
Title::Title()
	:Task((int)ETaskPrio::Title, 0, eType_Title)
	,m_cnt(0)
	,m_moveCnt(60*3)
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
	m_moveCnt--;
	if (m_moveCnt <= 0) {
		CVector3D pos(Utility::Rand(1000.0f , 3000.f ),
			Utility::Rand(1080.0f, 1080.0f),
			Utility::Rand(0.0f, 0.0f));
		new TitleEffect("TitleEffect", pos);
		m_moveCnt = 60 * 3;
	}
}

void Title::Render()
{
	m_img.Draw();
}
