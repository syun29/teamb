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

CVector2D ObjectBase::CalcScreenPos(bool grounded) const
{
	return CalcScreenPos(m_pos,grounded);
}

// 3�������W����2�������W���v�Z
CVector2D ObjectBase::CalcScreenPos(const CVector3D& pos,bool grounded) const
{
	CVector2D ret;

	// X���W�͂��̂܂ܐݒ�
	ret.x = pos.x-m_scroll.x;

	float size = 5500;
	float r = size / 2;
	float x = ret.x - SCREEN_WIDTH / 2;
	float a = x / r;

	float ground = FIELD_CENTER_Z + (r - cos(a) * r);
	
	// �ʏ���W�����߂�ꍇ
	if (!grounded)
	{
		// Y���W�́A3�������W��Y�i�����j��Z�i���s�j�����킹��
		float posZ = ground + pos.z;
		ret.y = -pos.y + posZ;
	}
	// �������l�����Ȃ��n�ʂ̈ʒu�����߂�ꍇ
	else
	{
		// Y���W�́A3�������W��Z�i���s�j�̂ݔ��f����
		ret.y = ground + pos.z;
	}

	return ret;
}

void ObjectBase::Update()
{
}

void ObjectBase::Render()
{
}

CVector2D ObjectBase::CalcScreenSize(const CVector2D& base_Size) const
{
	CVector2D ret;
	ret = base_Size * (800 -(- m_pos.z)) /800;
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

bool ObjectBase::CollisionCube(ObjectBase* b1, ObjectBase* b2)
{
	b1->m_max = b1->m_pos + b1->m_cubeMax;
	b1->m_min = b1->m_pos - b1->m_cubeMin;
	b2->m_max = b2->m_pos + b2->m_cubeMax;
	b2->m_min = b2->m_pos - b2->m_cubeMin;

	if (b1->m_min.x > b2->m_max.x || b1->m_max.x < b2->m_min.x ||
		b1->m_min.y > b2->m_max.y || b1->m_max.y < b2->m_min.y ||
		b1->m_min.z > b2->m_max.z || b1->m_max.z < b2->m_min.z) 
	{
		return false;
	}
		
	return true;
}

void ObjectBase::RenderCubu()
{
#ifdef _DEBUG
	m_max = m_pos + m_cubeMax;
	m_min = m_pos - m_cubeMin;
	Utility::DrawQuad(CalcScreenPos(CVector3D(m_min.x, m_max.y, m_pos.z)),
		CVector2D(m_cubeMax.x + m_cubeMin.x, m_cubeMax.y + m_cubeMin.y), CVector4D(1, 1, 0, 0.5f));
#endif 

	

}


