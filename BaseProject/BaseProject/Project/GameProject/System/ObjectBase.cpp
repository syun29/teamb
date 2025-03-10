#include "ObjectBase.h"
#define FIELD_CENTER_Z (SCREEN_HEIGHT * 0.75f)

CVector3D ObjectBase::m_scroll(0, 0, 0);
// �R���X�g���N�^
ObjectBase::ObjectBase( int type)
	: ObjectBase(CVector3D::zero,type)
{
}

ObjectBase::ObjectBase(const CVector3D& pos,int type)
	: Task((int)ETaskPrio::Object,0,type)
	, m_pos(pos)
	, m_isGrounded(true)
	, mp_shadowImg(nullptr)
{
	// �e�̉摜��ǂݍ���
	mp_shadowImg = CImage::CreateImage("Image/shadow.png");
	mp_shadowImg->SetCenter(mp_shadowImg->GetSize() * 0.5f);
}

// �f�X�g���N�^
ObjectBase::~ObjectBase()
{
	// �e�̉摜�f�[�^���폜
	if (mp_shadowImg != nullptr)
	{
		delete mp_shadowImg;
		mp_shadowImg = nullptr;
	}
}

// ���W���擾
const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

// ���W��ݒ�
void ObjectBase::SetPos(const CVector3D& pos)
{
	m_pos = pos;
}

// 3�������W����2�������W���v�Z
CVector2D ObjectBase::CalcScreenPos(bool grounded) const
{
	CVector2D ret;

	// X���W�͂��̂܂ܐݒ�
	ret.x = m_pos.x-m_scroll.x;
	
	// �ʏ���W�����߂�ꍇ
	if (!grounded)
	{
		// Y���W�́A3�������W��Y�i�����j��Z�i���s�j�����킹��
		float posZ = FIELD_CENTER_Z + m_pos.z;
		ret.y = -m_pos.y + posZ;
	}
	// �������l�����Ȃ��n�ʂ̈ʒu�����߂�ꍇ
	else
	{
		// Y���W�́A3�������W��Z�i���s�j�̂ݔ��f����
		ret.y = FIELD_CENTER_Z + m_pos.z;
	}

	return ret;
}

// �e�`��
void ObjectBase::RenderShadow()
{
	// �e��n�ʂ̈ʒu�ŕ`��
	mp_shadowImg->SetPos(CalcScreenPos(true));
	mp_shadowImg->Draw();
}

CVector3D ObjectBase::GetScreenPos(const CVector3D& pos)
{
	return pos - m_scroll;
}

bool ObjectBase::CollisionCube(Task* b1, Task* b2)
{
	b1->m_max = b1->m_pos + b1->m_cube;
	b1->m_min = b1->m_pos - b1->m_cube;
	b2->m_max = b2->m_pos + b2->m_cube;
	b2->m_min = b2->m_pos - b2->m_cube;

	if (b1->m_min.x > b2->m_max.x || b1->m_max.x < b2->m_min.x &&
		b1->m_min.y > b2->m_max.y || b1->m_max.y < b2->m_min.y &&
		b1->m_min.z > b2->m_max.z || b1->m_max.z < b2->m_min.z) 
	{
		return true;
	}
		
	return false;
}
