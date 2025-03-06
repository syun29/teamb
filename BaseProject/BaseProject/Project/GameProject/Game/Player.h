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
	//���
	enum class EState
	{
		Idle,	//�ҋ@���
		Jump,	//�W�����v��
		Death,	//���S
	};
	void ChangeState(EState state);

	//�ړ������̍X�V
	bool UpdateMove();

	//�ҋ@���̍X�V����
	void StateIdle();
	//�W�����v���̍X�V����
	void StateJump();
	//���S���̍X�V����
	void StateDeath();

	EState m_state;
	int m_stateStep;

	//�A�j���[�V�����̎��
	enum class EAnimType
	{
		Idle,	//�ҋ@
		Move,	//�ړ�
		Jump,	//�W�����v
		Death,	//���S

		Num,
	};
	static TexAnimData ANIM_DATA[];
	CImage* mp_image;	//�v���C���[�̉摜

	float m_moveSpeedY;	//Y��(����)�̈ړ����x
};