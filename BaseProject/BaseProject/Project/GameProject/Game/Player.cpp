#include"Player.h"

#define CHIP_SIZE 260 //1�R�}�̃T�C�Y
#define CENTER_POS CVector2D(128.0f,128.0f) //���S���W
#define MOVE_SPEED_X 3.0f //�������̈ړ����x
#define MOVE_SPEED_Z 3.0f //�������̈ړ����x
#define JUMP_SPEED 15.0f	// �W�����v���x
#define GRAVITY	-1.0F	//�d��

//�v���C���[�̃A�j���[�V�����f�[�^�̑O�錾
TexAnimData Player::ANIM_DATA[4] =
{
	//�ҋ@�A�j���[�V����
	{
		new TexAnim[2]
	{
		{15,12},{16,12},
	},
	2
},
	//�ړ��A�j���[�V����
	{
		new TexAnim[5]
	{
		{5,6},{6,6},{7,6},
		{8,6},{9,6},
	},
	5
	},
	//�W�����v�A�j���[�V����
	{
		new TexAnim[4]
	{
		{0,6},{1,6},{2,6},{3,6}
	},
	4
},
	//�_���[�W�A�j���[�V����
	{
		new TexAnim[2]
	{
		{10,12},{11,12},
	},
	2
},
};

//�R���X�g���N�^
Player::Player(const CVector3D& pos)
	:ObjectBase(pos,eType_Player)
{
	m_pos = pos;

	//�v���C���[�̉摜��ǂݍ���
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(CENTER_POS);
	m_rad = 50;
}

//�f�X�g���N�^
Player::~Player()
{
	//�f�X�g���N�^
	//delete m_img;
}

//���݂̏�Ԃ�؂�ւ�
void Player::ChangeState(EState state)
{
	if (m_state == state) return;

	m_state = state;
	m_stateStep = 0;

}

//�ړ������̍X�V
bool Player::UpdateMove()
{
	bool isMove = false;
	//���L�[�������Ă����
	if (HOLD(CInput::eLeft))
	{
		//�������ֈړ�
		m_pos.x -= MOVE_SPEED_X;
		m_img.SetFlipH(true);
		isMove = true;
	}
	//�E�L�[�������Ă����
	else if (HOLD(CInput::eRight))
	{
		//�E�����ֈړ�
		m_pos.x += MOVE_SPEED_X;
		m_img.SetFlipH(false);
		isMove = true;
	}
	//��L�[�������Ă����
	if (HOLD(CInput::eUp))
	{
		//�������ֈړ�
		m_pos.z -= MOVE_SPEED_Z;
		isMove = true;
	}
	//���L�[�������Ă����
	else if (HOLD(CInput::eDown))
	{
		//��O�����ֈړ�
		m_pos.z += MOVE_SPEED_Z;
		isMove = true;
	}

	return isMove;
}

//�ҋ@���̍X�V����
void Player::StateIdle()
{
	//�ړ�����
	bool isMove = UpdateMove();

	//�ړ���Ԃɍ��킹�āA�A�j���[�V������؂�ւ�
	EAnimType anim = isMove ? EAnimType::Move : EAnimType::Idle;
	m_img.ChangeAnimation((int)anim);

	//space�L�[�ŃW�����v��Ԃֈڍs
	if (PUSH(CInput::eButton5))
	{
		ChangeState(EState::Jump);
	}

	else if (PUSH(CInput::eButton1))
	{
		ChangeState(EState::Damage);
	}
}

//�W�����v���̍X�V����
void Player::StateJump()
{
	//�X�e�b�v���Ƃɏ�����؂�ւ�
	switch (m_stateStep)
	{
		//�X�e�b�v0:�W�����v�J�n
	case 0:
		//Y��(����)�̈ړ����x�ɃW�����v���x��ݒ肵�A
		//�ڒn��Ԃ���������
		m_moveSpeedY = JUMP_SPEED;
		m_isGrounded = false;
		m_stateStep++;
		break;
		//�X�e�b�v1:�W�����v�I��
	case 1:
		//�ڒn������A�ҋ@��Ԃֈڍs
		if (m_isGrounded)
		{
			ChangeState(EState::Idle);
		}
		break;
	}

	//�ړ�����
	bool isMove=UpdateMove();
	m_img.ChangeAnimation((int)EAnimType::Jump);
}

//���S���̍X�V����
void Player::StateDamage()
{
	//�X�e�b�v���Ƃɏ�����؂�ւ�
	switch (m_stateStep)
	{
		//�X�e�b�v0:�_���[�W�A�j���[�V�����ɐ؂�ւ�
	case 0:
		m_img.ChangeAnimation((int)EAnimType::Damage, false);
		m_stateStep++;
		break;
		//�X�e�b�v1:�A�j���[�V�����I���҂�
	case 1:
		//�U���A�j���[�V�������I��������A�ҋ@��Ԃֈڍs
		if (m_img.CheckAnimationEnd())
		{
			ChangeState(EState::Idle);
		}
		break;
	}
	
}

//�X�V����
void Player::Update()
{
	//���݂̏�Ԃɍ��킹�āA������؂�ւ���
	switch (m_state)
	{
	case EState::Idle:		StateIdle();	break;
	case EState::Jump:		StateJump();	break;
	case EState::Damage:		StateDamage();	break;
	}

	//Y��(����)�̈ړ������W�ɔ��f
	m_pos.y += m_moveSpeedY;
	m_moveSpeedY += GRAVITY;	//Y���̈ړ����x�ɏd�͂����Z
	//�n�ʂ�艺�ɂ�����
	if (m_pos.y <= 0.0f)
	{
		//�n�ʂ̍��W�֖߂�
		m_pos.y = 0.0f;
		m_moveSpeedY = 0.0f;
		m_isGrounded = true;
	}

	//�C���[�W�ɍ��W��ݒ肵�āA�A�j���[�V�������X�V
	m_img.SetPos(CalcScreenPos());
	m_img.UpdateAnimation();
	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280/2;
}

//�`�揈��
void Player::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
}
