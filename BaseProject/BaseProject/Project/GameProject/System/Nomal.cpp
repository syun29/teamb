#include "Nomal.h"

#define CHIP_SIZE 137

//���̃A�j���[�V�����f�[�^
TexAnimData Nomal::ANIM_DATA[1] =
{
	{
		new TexAnim[4]
	{
		{0,12},{1,12},{2,12},{3,12},
	},4

	}
};

//�R���X�g���N�^
Nomal::Nomal(const CVector3D& pos)
	:ObjectBase(pos,eType_Star)
{
	//�摜�ǂݍ���
	m_img = COPY_RESOURCE("Nomal", CImage);
	m_pos = pos;
	m_img.ChangeAnimation(0);
	m_cnt = 0;

}
Nomal::~Nomal()
{
}

void Nomal::Update()
{
/*	m_cnt--;
	if (m_cnt <= 0) {
		m_cnt = 300;
		new Nomal(
			CVector3D(100.0f, 100.0f, 0.0f));
	}*/

	m_img.UpdateAnimation();
}

void Nomal::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
}
