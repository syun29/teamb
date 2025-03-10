#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//コンストラクタ
	Enemy(const CVector3D& pos, CVector3D& cube);
	//デストラクタ
	~Enemy();

	//更新処理
	void Update();
	//描画処理
	void Render();
	CImage m_img;
	int m_rad;
private:
	//static TexAnimData ANIM_DATA[];
	void Collision(Task*b);
	//CImage* mp_image; //プレイヤーの画像
};