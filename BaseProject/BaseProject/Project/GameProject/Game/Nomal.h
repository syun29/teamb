#pragma once
#include"../System/ObjectBase.h"

class Nomal :public ObjectBase
{
public:
	//コンストラクタ
	Nomal(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin);
	//デストラクタ
	~Nomal();

	//更新処理
	void Update();
	//描画処理
	void Render();

	CImage m_img;
	int m_cnt;
	static TexAnimData ANIM_DATA[];

private:
	void Collision(Task* b);
};
