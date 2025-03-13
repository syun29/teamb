#pragma once
#include"../System/StarBase.h"

class Constellation_Star :public StarBase
{
public:
	//�R���X�g���N�^
	Constellation_Star(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin,int kinds);
	//�f�X�g���N�^
	~Constellation_Star();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();
	int kind;
	CImage m_img;
	CImage m_tri;//�O�p�`
	CImage m_quad;//�l�p�`
	CImage m_penta;//�܊p�`
private:
	void Collision(Task* b);

};