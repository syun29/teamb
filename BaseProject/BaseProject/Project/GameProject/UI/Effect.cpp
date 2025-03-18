#include "Effect.h"
TexAnimData Effect::ANIM_DATA[1] =
{
	//待機アニメーション
	{
		new TexAnim[9]
	{
		{0,5*2},{1,5*2},{3,5*2},{4,5*2},{5,5*2},{6,5*2},
		{7,5*2},{8,5*2},{9,5*2}
	},
	9
	},
};
Effect::Effect(const char*name,const CVector3D& pos)
	:Task((int)ETaskPrio::Effect, 0, eType_Effect)
	,m_pos(pos)

{
	m_img = COPY_RESOURCE(name, CImage);
	m_img.ChangeAnimation(0);
	
}

Effect::~Effect()
{
}

void Effect::Update()
{
	m_img.UpdateAnimation();
	/*if (m_img.CheckAnimationEnd())
	{

		Kill();
	}*/
}

void Effect::Render()
{

	m_img.SetSize(64*2,64*2);
	m_img.SetCenter(64,64);
	m_img.Draw();
}
