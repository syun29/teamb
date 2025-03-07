#pragma once
#include"Task.h"

// �S�ẴI�u�W�F�N�g�̃x�[�X�N���X
class ObjectBase:public Task
{
public:
	// �R���X�g���N�^
	ObjectBase();
	ObjectBase(const CVector3D& pos);
	// �f�X�g���N�^
	virtual ~ObjectBase();

	// ���W���擾
	const CVector3D& GetPos() const;
	// ���W��ݒ�
	void SetPos(const CVector3D& pos);
	static CVector3D m_scroll;

	/// <summary>
	/// 3�������W����X�N���[�����W�i2D�j�ɕϊ�
	/// </summary>
	/// <param name="grounded">true�Ȃ�΁A�����͍l�������n�ʂ̈ʒu��Ԃ�</param>
	/// <returns>�X�N���[�����W</returns>
	CVector2D CalcScreenPos(bool grounded = false) const;

	// �e�`��
	virtual void RenderShadow();

	static CVector3D GetScreenPos(const CVector3D& pos);

protected:
	CVector3D m_pos;		// �I�u�W�F�N�g�̍��W
	bool m_isGrounded;		// �n�ʂɐڒn���Ă��邩�ǂ���
	CImage* mp_shadowImg;	// �e�̉摜
};