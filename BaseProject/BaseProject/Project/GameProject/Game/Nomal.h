#pragma once
#include"../System/ObjectBase.h"

class Nomal :public ObjectBase
{
public:
	//�R���X�g���N�^
	Nomal(const CVector3D& pos);
	//�f�X�g���N�^
	~Nomal();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	CImage m_img;
	int m_cnt;
	static TexAnimData ANIM_DATA[];

private:
	void Collision(Task* b);
};
