#include"Player.h"

#define CHIP_SIZE 24 //1�R�}�̃T�C�Y
#define CENTER_POS CVector2D(12.0f,12.0f) //���S���W
#define MOVE_SPEED_X 3.0f //�������̈ړ����x
#define MOVE_SPEED_Y 3.0f //�c�����̈ړ����x

//�v���C���[�̃A�j���[�V�����f�[�^�̑O�錾
TexAnimData Player::ANIM_DATA[4] =
{
	//�ҋ@�A�j���[�V����
	{
		new TexAnim[2]
	{
		{0,6},{1,6},
	},
	2
},
	//�ړ��A�j���[�V����

	//�W�����v�A�j���[�V����

	//�_���[�W�A�j���[�V����
};

//�R���X�g���N�^
Player::Player(const CVector2D& pos)
	:mp_image(nullptr)
{
	m_pos = pos;

	//�v���C���[�̉摜��ǂݍ���
	mp_image = CImage::CreateImage(
		"Image/AnimationSheet.png", //�摜�t�@�C���̃p�X
		ANIM_DATA, //�A�j���[�V�����̃f�[�^
		CHIP_SIZE,CHIP_SIZE //1�R�}�̕��ƍ���
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(CENTER_POS);
}

//�f�X�g���N�^
Player::~Player()
{
}

//�X�V����
void Player::Update()
{
}

//�`�揈��
void Player::Render()
{
	mp_image->SetPos(m_pos);
	mp_image->Draw();
}
