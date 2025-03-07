#include "Nomal.h"

//���̃A�j���[�V�����f�[�^
TexAnimData Nomal::ANIM_DATA[1] =
{
	{
		new TexAnim[4]
	{
		{0,6},{1,6},{2,6},{3,6},
	},4

	}
};

//�R���X�g���N�^
Nomal::Nomal(const CVector3D& pos)
	:ObjectBase(pos)
{
	//�摜�ǂݍ���
	m_img = COPY_RESOURCE("Nomal", CImage);
	m_img.ChangeAnimation(0);

}
Nomal::~Nomal()
{
}

void Nomal::Update()
{
}

void Nomal::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
}
