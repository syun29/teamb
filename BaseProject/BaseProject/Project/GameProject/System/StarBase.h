#pragma once
#include "ObjectBase.h"

// キャラクターのベースクラス
class StarBase : public ObjectBase
{
public:
	// コンストラクタ
	StarBase();
	StarBase(const CVector3D& pos);
	// デストラクタ
	virtual ~StarBase();

	void TakeScore();

protected:
	int score;
};
