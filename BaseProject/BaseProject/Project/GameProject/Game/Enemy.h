#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//コンストラクタ
	Enemy(const CVector3D& pos);
	//デストラクタ
	~Enemy();

	//更新処理
	void Update();
	//描画処理
	void Render();
	CImage m_img;
private:
	//static TexAnimData ANIM_DATA[];

	//CImage* mp_image; //プレイヤーの画像
};