#pragma once
#include"../System/ObjectBase.h"

class Player:public ObjectBase
{
public:
	//�R���X�g���N�^
	Player(const CVector2D& pos);
	//�f�X�g���N�^
	~Player();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

private:
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //�v���C���[�̉摜
};