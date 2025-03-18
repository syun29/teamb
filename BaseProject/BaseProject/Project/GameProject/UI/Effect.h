#pragma once
#include "System/ObjectBase.h"
class Effect :public ObjectBase 
{
public:
	Effect(const char* name, const CVector3D& pos);
	~Effect();
	static TexAnimData ANIM_DATA[];


	
	CImage m_img;
	CVector3D m_pos;
	void Update();
	void Render();
};
class PerticleEffect :public ObjectBase
{
public:
	PerticleEffect(const char* name, const CVector3D& pos, const CVector3D& vec, const CVector2D& size);
	~PerticleEffect();
	static TexAnimData ANIM_DATA[];

	CImage m_img;
	CVector3D m_pos;
	CVector3D m_vec;
	CVector2D m_size;
	float alpfa;
	float scale;
	void Update();
	void Render();
};