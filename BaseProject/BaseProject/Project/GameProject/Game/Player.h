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
	//状態
	enum class EState
	{
		Idle,	//待機状態
		Jump,	//ジャンプ中
		Death,	//死亡
	};
	void ChangeState(EState state);

	//移動処理の更新
	bool UpdateMove();

	//待機中の更新処理
	void StateIdle();
	//ジャンプ中の更新処理
	void StateJump();
	//死亡時の更新処理
	void StateDeath();

	EState m_state;
	int m_stateStep;

	//アニメーションの種類
	enum class EAnimType
	{
		Idle,	//待機
		Move,	//移動
		Jump,	//ジャンプ
		Death,	//死亡

		Num,
	};
	static TexAnimData ANIM_DATA[];
	CImage* mp_image;	//プレイヤーの画像

	float m_moveSpeedY;	//Y軸(高さ)の移動速度
};