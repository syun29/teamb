#pragma once
#include "ObjectBase.h"

// �L�����N�^�[�̃x�[�X�N���X
class StarBase : public ObjectBase
{
public:
	// �R���X�g���N�^
	StarBase();
	StarBase(const CVector3D& pos);
	// �f�X�g���N�^
	virtual ~StarBase();

	void TakeScore();

protected:
	int score;
};
