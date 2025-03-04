#include"Player.h"

#define CHIP_SIZE 24 //1コマのサイズ
#define CENTER_POS CVector2D(12.0f,12.0f) //中心座標
#define MOVE_SPEED_X 3.0f //横方向の移動速度
#define MOVE_SPEED_Y 3.0f //縦方向の移動速度

//プレイヤーのアニメーションデータの前宣言
TexAnimData Player::ANIM_DATA[4] =
{
	//待機アニメーション
	{
		new TexAnim[2]
	{
		{0,6},{1,6},
	},
	2
},
	//移動アニメーション

	//ジャンプアニメーション

	//ダメージアニメーション
};

//コンストラクタ
Player::Player(const CVector2D& pos)
	:mp_image(nullptr)
{
	m_pos = pos;

	//プレイヤーの画像を読み込み
	mp_image = CImage::CreateImage(
		"Image/AnimationSheet.png", //画像ファイルのパス
		ANIM_DATA, //アニメーションのデータ
		CHIP_SIZE,CHIP_SIZE //1コマの幅と高さ
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(CENTER_POS);
}

//デストラクタ
Player::~Player()
{
}

//更新処理
void Player::Update()
{
}

//描画処理
void Player::Render()
{
	mp_image->SetPos(m_pos);
	mp_image->Draw();
}
