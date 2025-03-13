#include"Player.h"

#define CHIP_SIZE 260 //1コマのサイズ
#define CENTER_POS CVector2D(128.0f,280.0f) //中心座標
#define MOVE_SPEED_X 3.0f //横方向の移動速度
#define MOVE_SPEED_Z 3.0f //奥方向の移動速度
#define JUMP_SPEED 15.0f	// ジャンプ速度
#define GRAVITY	-0.50f	//重力

//プレイヤーのアニメーションデータの前宣言
TexAnimData Player::ANIM_DATA[4] =
{
	//待機アニメーション
	{
		new TexAnim[2]
	{
		{15,12},{16,12},
	},
	2
},
	//移動アニメーション
	{
		new TexAnim[5]
	{
		{5,6},{6,6},{7,6},
		{8,6},{9,6},
	},
	5
	},
	//ジャンプアニメーション
	{
		new TexAnim[4]
	{
		{0,6},{1,6},{2,6},{3,6}
	},
	4
},
	//ダメージアニメーション
	{
		new TexAnim[2]
	{
		{10,12},{11,12},
	},
	2
},
};

//コンストラクタ
Player::Player(const CVector3D& pos, CVector3D& cubeMax, CVector3D& cubeMin)
	:ObjectBase(pos,eType_Player)
{
	m_pos = pos;

	//プレイヤーの画像を読み込み
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(CENTER_POS);
	m_cubeMax = cubeMax;
	m_cubeMin = cubeMin;
}

//デストラクタ
Player::~Player()
{
	//デストラクタ
	//delete m_img;
}

//現在の状態を切り替え
void Player::ChangeState(EState state)
{
	if (m_state == state) return;

	m_state = state;
	m_stateStep = 0;

}

//移動処理の更新
bool Player::UpdateMove()
{
	bool isMove = false;
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		//左方向へ移動
		m_pos.x -= MOVE_SPEED_X;
		m_img.SetFlipH(true);
		isMove = true;
	}
	//右キーを押している間
	else if (HOLD(CInput::eRight))
	{
		//右方向へ移動
		m_pos.x += MOVE_SPEED_X;
		m_img.SetFlipH(false);
		isMove = true;
	}
	//上キーを押している間
	if (HOLD(CInput::eUp))
	{
		if (m_pos.z >= -50)
		{

			//奥方向へ移動
			m_pos.z -= MOVE_SPEED_Z;
			isMove = true;
		}
	}
	//下キーを押している間
	else if (HOLD(CInput::eDown))
	{
		if (m_pos.z <= 200)
		{
			//手前方向へ移動
			m_pos.z += MOVE_SPEED_Z;
			isMove = true;
		}
	}

	return isMove;
}

//待機時の更新処理
void Player::StateIdle()
{
	//移動処理
	bool isMove = UpdateMove();

	//移動状態に合わせて、アニメーションを切り替え
	EAnimType anim = isMove ? EAnimType::Move : EAnimType::Idle;
	m_img.ChangeAnimation((int)anim);

	//spaceキーでジャンプ状態へ移行
	if (PUSH(CInput::eButton5))
	{
		ChangeState(EState::Jump);
	}

	/*else if (PUSH(CInput::eButton1))
	{
		ChangeState(EState::Damage);
	}*/
}

//ジャンプ中の更新処理
void Player::StateJump()
{
	//ステップごとに処理を切り替え
	switch (m_stateStep)
	{
		//ステップ0:ジャンプ開始
	case 0:
		//Y軸(高さ)の移動速度にジャンプ速度を設定し、
		//接地状態を解除する
		m_moveSpeedY = JUMP_SPEED;
		m_isGrounded = false;
		m_stateStep++;
		break;
		//ステップ1:ジャンプ終了
	case 1:
		//接地したら、待機状態へ移行
		if (m_isGrounded)
		{
			ChangeState(EState::Idle);
		}
		break;
	}

	//移動処理
	bool isMove=UpdateMove();
	m_img.ChangeAnimation((int)EAnimType::Jump);
}

//ダメージ時の更新処理
void Player::StateDamage()
{
	//ステップごとに処理を切り替え
	switch (m_stateStep)
	{
		//ステップ0:ダメージアニメーションに切り替え
	case 0:
		m_img.ChangeAnimation((int)EAnimType::Damage, false);
		m_stateStep++;
		break;
		//ステップ1:アニメーション終了待ち
	case 1:
		//アニメーションが終了したら、待機状態へ移行
		if (m_img.CheckAnimationEnd())
		{
			ChangeState(EState::Idle);
		}
		break;
	}
	
}

void Player::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Enemy: {
		if (ObjectBase::CollisionCube(this, dynamic_cast<ObjectBase*>(b)))
		{
			ChangeState(EState::Damage);
		}
	}
	}
}



//更新処理
void Player::Update()
{
	//現在の状態に合わせて、処理を切り替える
	switch (m_state)
	{
	case EState::Idle:		StateIdle();	break;
	case EState::Jump:		StateJump();	break;
	case EState::Damage:		StateDamage();	break;
	}

	//Y軸(高さ)の移動を座標に反映
	m_pos.y += m_moveSpeedY;
	m_moveSpeedY += GRAVITY;	//Y軸の移動速度に重力を加算
	//地面より下にいくと
	if (m_pos.y <= 0.0f)
	{
		//地面の座標へ戻す
		m_pos.y = 0.0f;
		m_moveSpeedY = 0.0f;
		m_isGrounded = true;
	}

	//イメージに座標を設定して、アニメーションを更新
	m_img.SetPos(CalcScreenPos());
	m_img.UpdateAnimation();
	//スクロール設定
	m_scroll.x = m_pos.x - 1280/2;

}

//描画処理
void Player::Render()
{

	RenderShadow();

	CVector2D size = CalcScreenSize(CVector2D(260,260));
	m_img.SetSize(size);
	m_img.SetCenter(size.x / 2, size.y);
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
}
