#include "Result.h"
#include "../System/TaskManager.h"
#include "Game.h"
#include "UI/score.h"
#include "UI/Timer.h"
#include "Game/Constellation.h"
#include"Title/Title.h"

Result::Result() : Task((int)ETaskPrio::Result, 0, eType_Result)
{
    //‰æ‘œ•¡»
    m_img = COPY_RESOURCE("Result", CImage);
    m_scr = COPY_RESOURCE("Score", CImage);
    m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Result::Update()
{
    if (PUSH(CInput::eButton10)) {
        SOUND("Result")->Stop();
        TaskManager::Instance()->DeleteAll();
        new Title();
        SOUND("Title")->Play();
        Score::s_score = 0;
        Timer::resetTime();
        Constellation::starCnt[0] = {0};
        Constellation::starCnt[1] = { 0 };
        Constellation::starCnt[2] = { 0 };
    }
}

void Result::Render()
{
     m_img.Draw();
    int Resultscore = Score::s_score;
    for (int i = 0; i < 6; i++, Resultscore /= 10) {
        int r = Resultscore % 10;
        m_scr.SetRect(102 * r,0, 102 * r + 102, 169);
        m_scr.SetSize(150, 110);
        m_scr.SetPos(700 - 102 * i, 1000 / 2);
        m_scr.Draw();
    }

}
