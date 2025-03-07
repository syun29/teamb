#include "Nomal.h"

//星のアニメーションデータ
TexAnimData Nomal::ANIM_DATA[1] =
{
	{
		new TexAnim[4]
	{
		{0,6},{1,6},{2,6},{3,6},
	},4

	}
};

//コンストラクタ
Nomal::Nomal(const CVector3D& pos)
	:ObjectBase(pos)
{
	//画像読み込み
	m_img = COPY_RESOURCE("Nomal", CImage);
	m_img.ChangeAnimation(0);

}
Nomal::~Nomal()
{
}

void Nomal::Update()
{
}

void Nomal::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.Draw();
}
