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
	void Update() override;
	//�`�揈��
	void Render()override;
	CImage m_img;

private:
	//static TexAnimData ANIM_DATA[];
	void Collision(Task*b);
	//CImage* mp_image; //�v���C���[�̉摜
};