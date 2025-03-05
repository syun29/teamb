#pragma once
#include"../System/ObjectBase.h"

class Player:public ObjectBase
{
public:
	//コンストラクタ
	Player(const CVector2D& pos);
	//デストラクタ
	~Player();

	//更新処理
	void Update();
	//描画処理
	void Render();

private:
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //プレイヤーの画像
};