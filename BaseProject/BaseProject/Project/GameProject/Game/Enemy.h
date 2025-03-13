#pragma once
#include"../System/ObjectBase.h"

class Enemy :public ObjectBase
{
public:
	//コンストラクタ
	Enemy(const CVector3D& pos, CVector3D& cubeMax,CVector3D& cubeMin);
	//デストラクタ
	~Enemy();

	//更新処理
	void Update() override;
	//描画処理
	void Render()override;
	CImage m_img;

private:
	//static TexAnimData ANIM_DATA[];
	void Collision(Task*b);
	//CImage* mp_image; //プレイヤーの画像
};