#pragma once
#include "../System/Task.h"

class Result : public Task {
public:
    CImage m_img;
    CImage m_scr;
    //�R���g���X�^
    Result();
    void Update();
    void Render();

};
