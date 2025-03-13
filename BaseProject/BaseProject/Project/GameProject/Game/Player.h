#pragma once
#include"../System/ObjectBase.h"

class Player:public ObjectBase
{
public:
	//�R���X�g���N�^
	Player(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin);
	//�f�X�g���N�^
	~Player();

	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	CImage m_img;
	static TexAnimData ANIM_DATA[];


private:
	//���
	enum class EState
	{
		Idle,	//�ҋ@���
		Jump,	//�W�����v��
		Damage,	//�_���[�W
	};
	void ChangeState(EState state);

	//�ړ������̍X�V
	bool UpdateMove();

	//�ҋ@���̍X�V����
	void StateIdle();
	//�W�����v���̍X�V����
	void StateJump();
	//�_���[�W���̍X�V����
	void StateDamage();

	void Collision(Task* b);


	EState m_state;
	int m_stateStep;
	//�A�j���[�V�����̎��
	enum class EAnimType
	{
		Idle,	//�ҋ@
		Move,	//�ړ�
		Jump,	//�W�����v
		Damage,	//�_���[�W

		Num,
	};

	float m_moveSpeedY;	//Y��(����)�̈ړ����x
	
};