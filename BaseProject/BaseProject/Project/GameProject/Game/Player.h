#pragma once
#include"../System/ObjectBase.h"

class Player:public ObjectBase
{
public:
	//コンストラクタ
	Player(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin);
	//デストラクタ
	~Player();

	//更新処理
	void Update();
	//描画処理
	void Render();

	CImage m_img;
	static TexAnimData ANIM_DATA[];


private:
	//状態
	enum class EState
	{
		Idle,	//待機状態
		Jump,	//ジャンプ中
		Damage,	//ダメージ
	};
	void ChangeState(EState state);

	//移動処理の更新
	bool UpdateMove();

	//待機中の更新処理
	void StateIdle();
	//ジャンプ中の更新処理
	void StateJump();
	//ダメージ時の更新処理
	void StateDamage();

	void Collision(Task* b);


	EState m_state;
	int m_stateStep;
	//アニメーションの種類
	enum class EAnimType
	{
		Idle,	//待機
		Move,	//移動
		Jump,	//ジャンプ
		Damage,	//ダメージ

		Num,
	};

	float m_moveSpeedY;	//Y軸(高さ)の移動速度
	
};