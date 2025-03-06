#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//�R���X�g���N�^
	Enemy(const CVector2D& pos);
	//�f�X�g���N�^
	~Enemy();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

private:
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //�v���C���[�̉摜
};