#pragma once

class Player
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
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //�v���C���[�̉摜
	CVector2D m_pos; //�v���C���[�̍��W
};