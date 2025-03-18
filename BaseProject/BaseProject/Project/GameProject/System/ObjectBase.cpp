#include "ObjectBase.h"
#define FIELD_CENTER_Z (SCREEN_HEIGHT * 0.75f)

CVector3D ObjectBase::m_scroll(0, 0, 0);
// コンストラクタ
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
	// 影の画像を読み込み
	mp_shadowImg = CImage::CreateImage("Image/shadow.png");
	mp_shadowImg->SetCenter(mp_shadowImg->GetSize() * 0.5f);
}

// デストラクタ
ObjectBase::~ObjectBase()
{
	// 影の画像データを削除
	if (mp_shadowImg != nullptr)
	{
		delete mp_shadowImg;
		mp_shadowImg = nullptr;
	}
}

// 座標を取得
const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

// 座標を設定
void ObjectBase::SetPos(const CVector3D& pos)
{
	m_pos = pos;
}

CVector2D ObjectBase::CalcScreenPos(bool grounded) const
{
	return CalcScreenPos(m_pos,grounded);
}

// 3次元座標から2次元座標を計算
CVector2D ObjectBase::CalcScreenPos(const CVector3D& pos,bool grounded) const
{
	CVector2D ret;

	// X座標はそのまま設定
	ret.x = pos.x-m_scroll.x;

	float size = 5500;
	float r = size / 2;
	float x = ret.x - SCREEN_WIDTH / 2;
	float a = x / r;

	float ground = FIELD_CENTER_Z + (r - cos(a) * r);
	
	// 通常座標を求める場合
	if (!grounded)
	{
		// Y座標は、3次元座標のY（高さ）とZ（奥行）を合わせる
		float posZ = ground + pos.z;
		ret.y = -pos.y + posZ;
	}
	// 高さを考慮しない地面の位置を求める場合
	else
	{
		// Y座標は、3次元座標のZ（奥行）のみ反映する
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

// 影描画
void ObjectBase::RenderShadow()
{
	// 影を地面の位置で描画
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


