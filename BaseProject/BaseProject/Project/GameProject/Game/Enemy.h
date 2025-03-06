#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//コンストラクタ
	Enemy(const CVector2D& pos);
	//デストラクタ
	~Enemy();

	//更新処理
	void Update();
	//描画処理
	void Render();

private:
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //プレイヤーの画像
};