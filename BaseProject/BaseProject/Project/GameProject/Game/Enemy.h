#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//�R���X�g���N�^
	Enemy(const CVector3D& pos, CVector3D& cubeMax,CVector3D& cubeMin);
	//�f�X�g���N�^
	~Enemy();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();
	CImage m_img;
	int test;
private:
	//static TexAnimData ANIM_DATA[];
	void Collision(Task*b);
	//CImage* mp_image; //�v���C���[�̉摜
};