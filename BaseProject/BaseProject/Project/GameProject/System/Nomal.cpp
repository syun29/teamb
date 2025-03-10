#include "Nomal.h"

#define CHIP_SIZE 137
#define CENTER_POS CVector3D(68.0f,68.0f)

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
	:ObjectBase(pos,eType_Star)
{
	//画像読み込み
	m_img = COPY_RESOURCE("Nomal", CImage);
	m_pos = pos;
	m_img.ChangeAnimation(0);

}
Nomal::~Nomal()
{
}

void Nomal::Update()
{
	m_img.UpdateAnimation();
}

void Nomal::Render()
{
	m_img.SetPos(100,100);
	m_img.Draw();
}
