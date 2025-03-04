#pragma once

class Player
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
	static TexAnimData ANIM_DATA[];

	CImage* mp_image; //プレイヤーの画像
	CVector2D m_pos; //プレイヤーの座標
};