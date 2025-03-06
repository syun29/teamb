#include"Player.h"

#define CHIP_SIZE 260 //1コマのサイズ
#define CENTER_POS CVector2D(128.0f,128.0f) //中心座標
#define MOVE_SPEED_X 3.0f //横方向の移動速度
#define MOVE_SPEED_Z 3.0f //奥方向の移動速度
#define MOVE_SPEED 15.0f	//重力

//プレイヤーのアニメーションデータの前宣言
TexAnimData Player::ANIM_DATA[4] =
{
	//待機アニメーション
	{
		new TexAnim[2]
	{
		{15,6},{16,6},
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
		{10,6},{11,6},
	},
	2
},
};

//コンストラクタ
Player::Player(const CVector2D& pos)
	:mp_image(nullptr)
{
	m_pos = pos;

	//プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage(
		"Image/_______________.png", //画像ファイルのパス
		ANIM_DATA, //アニメーションのデータ
		CHIP_SIZE,CHIP_SIZE //1コマの幅と高さ
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(CENTER_POS);
}

//デストラクタ
Player::~Player()
{
	//デストラクタ
	delete mp_image;
}


void Player::ChangeState(EState state)
{
	if (m_state == state) return;

	m_state = state;
	m_stateStep = 0;
}

bool Player::UpdateMove()
{
	bool isMove = false;
	//左キーを押している間
	if (HOLD(CInput::eLeft))
	{
		//左方向へ移動
		m_pos.x -= MOVE_SPEED_X;
		mp_image->SetFlipH(true);
		isMove = true;
	}
	//右キーを押している間
	else if (HOLD(CInput::eRight))
	{
		//右方向へ移動
		m_pos.x += MOVE_SPEED_X;
		mp_image->SetFlipH(false);
		isMove = true;
	}
	//上キーを押している間
	if (HOLD(CInput::eUp))
	{
		//奥方向へ移動
		m_pos.z -= MOVE_SPEED_Z;
		isMove = true;
	}
	//下キーを押している間
	else if (HOLD(CInput::eDown))
	{
		//手前方向へ移動
		m_pos.z -= MOVE_SPEED_Z;
		isMove = true;
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
	mp_image->ChangeAnimation((int)anim);

	//spaceキーでジャンプ状態へ移行
	if (PUSH(CInput::eButton5))
	{
		ChangeState(EState::Jump);
	}
}

void Player::StateRun()
{
}

void Player::StateJump()
{
}

void Player::StateDeath()
{
}

//更新処理
void Player::Update()
{
}

//描画処理
void Player::Render()
{
	mp_image->SetPos(CalcScreenPos());
	mp_image->Draw();
}
