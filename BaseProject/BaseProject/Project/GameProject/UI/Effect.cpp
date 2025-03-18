#include "Effect.h"
TexAnimData Effect::ANIM_DATA[1] =
{
	{
		new TexAnim[9]
	{
		{0,12},{1,12},{2,12}, { 3,12 },{4,12},{5,12},
	    {6,12},{7,12},{8,12}
	},
	9
	},
};
Effect::Effect(const char*name,const CVector3D& pos)
	:ObjectBase(pos, eType_Effect)


{
	
	m_img = COPY_RESOURCE(name, CImage);
	m_img.ChangeAnimation(0,false);
	
}

Effect::~Effect()
{
}

void Effect::Update()
{
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd())
	{

		Kill();
	}
}

void Effect::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.SetSize(64,64);
	m_img.SetRect(-16, 32, 16, 0);
	m_img.SetCenter(16,16);
	m_img.Draw();
}

PerticleEffect::PerticleEffect(const char* name, const CVector3D& pos, const CVector3D& vec, const CVector2D& size)
	:ObjectBase(pos, eType_Effect)
	,m_pos(pos)
	,m_vec(vec)
	,m_size(size)
	,alpfa(1.0)
	,scale(1.0)
{
	m_img = COPY_RESOURCE(name, CImage);
	//m_img.ChangeAnimation(0, false);

}

PerticleEffect::~PerticleEffect()
{
}

void PerticleEffect::Update()
{
	static float gravity =0.5;
	m_vec.y -= gravity;
	scale--;
	alpfa--;
	m_size.x -= alpfa;
	m_size.y -= scale;
	if (m_pos.y <= 0)
	{
		m_vec.x *= 1.5;
		m_vec.y *= 1.5;
	}
	if (scale <= 0)
	{
		Kill();
	}
}

void PerticleEffect::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.SetSize(50, 50);
	m_img.Draw();

}
