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

// 3次元座標から2次元座標を計算
CVector2D ObjectBase::CalcScreenPos(bool grounded) const
{
	CVector2D ret;

	// X座標はそのまま設定
	ret.x = m_pos.x-m_scroll.x;
	
	// 通常座標を求める場合
	if (!grounded)
	{
		// Y座標は、3次元座標のY（高さ）とZ（奥行）を合わせる
		float posZ = FIELD_CENTER_Z + m_pos.z;
		ret.y = -m_pos.y + posZ;
	}
	// 高さを考慮しない地面の位置を求める場合
	else
	{
		// Y座標は、3次元座標のZ（奥行）のみ反映する
		ret.y = FIELD_CENTER_Z + m_pos.z;
	}

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
