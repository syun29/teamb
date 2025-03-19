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
	m_pos += m_vec;
	m_size.x -= scale;
	m_size.y -= scale;

	if (m_pos.y <= 0)
	{
		m_vec.y *= -0.8;
	}
	if (m_size.x<=0)
	{
		Kill();
	}
}

void PerticleEffect::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.SetCenter(m_size / 2);
	m_img.SetSize(m_size);
	m_img.Draw();

}

TitleEffect::TitleEffect(const char* name, const CVector3D& pos)
	:ObjectBase(pos, eType_Effect)

{
	m_img = COPY_RESOURCE(name, CImage);

}

TitleEffect::~TitleEffect()
{
}

void TitleEffect::Update()
{
	m_pos.x -= 10.0f;
	m_pos.y -= 10.0f;
}

void TitleEffect::Render()
{
	m_img.SetPos(CalcScreenPos());
	m_img.SetCenter(250,250);
	m_img.SetSize(100,100);
	m_img.Draw();

}
