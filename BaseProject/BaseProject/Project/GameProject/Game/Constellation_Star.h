#pragma once
#include"../System/StarBase.h"

class Constellation_Star :public StarBase
{
public:
	//コンストラクタ
	Constellation_Star(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin,int kinds);
	//デストラクタ
	~Constellation_Star();

	//更新処理
	void Update();
	//描画処理
	void Render();
	int kind;
	CImage m_img;
	CImage m_tri;//三角形
	CImage m_quad;//四角形
	CImage m_penta;//五角形
private:
	void Collision(Task* b);

};