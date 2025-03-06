#include"Player.h"

#define CHIP_SIZE 260 //1�R�}�̃T�C�Y
#define CENTER_POS CVector2D(128.0f,128.0f) //���S���W
#define MOVE_SPEED_X 3.0f //�������̈ړ����x
#define MOVE_SPEED_Z 3.0f //�������̈ړ����x
#define MOVE_SPEED 15.0f	//�d��

//�v���C���[�̃A�j���[�V�����f�[�^�̑O�錾
TexAnimData Player::ANIM_DATA[4] =
{
	//�ҋ@�A�j���[�V����
	{
		new TexAnim[2]
	{
		{15,6},{16,6},
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
		{10,6},{11,6},
	},
	2
},
};

//�R���X�g���N�^
Player::Player(const CVector2D& pos)
	:mp_image(nullptr)
{
	m_pos = pos;

	//�v���C���[�̉摜��ǂݍ���
	mp_image = CImage::CreateImage(
		"Image/_______________.png", //�摜�t�@�C���̃p�X
		ANIM_DATA, //�A�j���[�V�����̃f�[�^
		CHIP_SIZE,CHIP_SIZE //1�R�}�̕��ƍ���
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(CENTER_POS);
}

//�f�X�g���N�^
Player::~Player()
{
	//�f�X�g���N�^
	delete mp_image;
}


void Player::ChangeState(EState state)
{
	if (m_state == state) return;

	m_state = state;
	m_stateStep = 0;
}

bool Player::UpdateMove()
{
	bool isMove = false;
	//���L�[�������Ă����
	if (HOLD(CInput::eLeft))
	{
		//�������ֈړ�
		m_pos.x -= MOVE_SPEED_X;
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//�E�L�[�������Ă����
	else if (HOLD(CInput::eRight))
	{
		//�E�����ֈړ�
		m_pos.x += MOVE_SPEED_X;
		mp_image->SetFlipH(false);
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
		m_pos.z -= MOVE_SPEED_Z;
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
	mp_image->ChangeAnimation((int)anim);

	//space�L�[�ŃW�����v��Ԃֈڍs
	if (PUSH(CInput::eButton5))
	{
		ChangeState(EState::Jump);
	}
}

void Player::StateRun()
{
}

void Player::StateJump()
{
}

void Player::StateDeath()
{
}

//�X�V����
void Player::Update()
{
}

//�`�揈��
void Player::Render()
{
	mp_image->SetPos(CalcScreenPos());
	mp_image->Draw();
}
