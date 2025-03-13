#pragma once
#include"Task.h"

// 全てのオブジェクトのベースクラス
class ObjectBase:public Task
{
public:
	// コンストラクタ
	ObjectBase(int type);
	ObjectBase(const CVector3D& pos,int type);
	// デストラクタ
	virtual ~ObjectBase();

	// 座標を取得
	const CVector3D& GetPos() const;
	// 座標を設定
	void SetPos(const CVector3D& pos);
	static CVector3D m_scroll;
	/// <summary>
	/// 3次元座標からスクリーン座標（2D）に変換
	/// </summary>
	/// <param name="grounded">trueならば、高さは考慮せず地面の位置を返す</param>
	/// <returns>スクリーン座標</returns>
	CVector2D CalcScreenPos(bool grounded = false) const;

	CVector2D CalcScreenSize(const CVector2D& base_Size)const;
	// 影描画
	virtual void RenderShadow();

	static CVector3D GetScreenPos(const CVector3D& pos);

	static bool CollisionCube(ObjectBase* b1, ObjectBase* b2);
protected:
	CVector3D m_pos;// オブジェクトの座標
	CVector3D m_max;
	CVector3D m_min;
	CVector3D m_cubeMax;	
	CVector3D m_cubeMin;
	bool m_isGrounded;		// 地面に接地してあるかどうか
	CImage* mp_shadowImg;	// 影の画像
};