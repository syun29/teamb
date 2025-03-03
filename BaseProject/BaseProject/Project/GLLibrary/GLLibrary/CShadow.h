#pragma once
#include "CMatrix.h"
#include "CLight.h"
#include "CCamera.h"
#include "CShader.h"
#include "CTextureFrame.h"
#include <functional>
#include <vector>
class CShadow {
public:
	enum {
		eNone,
		eShadow,
		eDisplay,
	};
	int		m_use_light;
	int		m_depthtexWidth;
	int		m_depthtexHeight;
	int		m_screenWidth;
	int		m_screenHeight;
	CMatrix m_lightProj;
	CMatrix m_lightView;
	float	m_lightHeight;
	float	m_lightViewLength;
	static int m_state;
	int m_shadow_idx;
	static int m_shadow_tex_cnt;
	void Render(std::function<void()> render);
	std::vector<CTextureFrame*> mp_render_target;
	static const int shadow_tex_offset=7;

	static std::vector<CShadow*> m_shadow_list;
	static std::vector<int> m_depth_tex_idx;
	static std::vector<CVector2D> m_depth_inv_tex_size;
	static std::vector<CMatrix> m_shadowMatrix;
	static float m_shadow_ambient;
public:
	/// <summary>
	/// �C���X�^���X����(���v12���܂ŁA�_�����͂U���A���P��������)
	/// </summary>
	/// <param name="length">�`��͈�</param>
	/// <param name="height">�`��J�n�̍���</param>
	/// <param name="texWidth">�e�N�X�`���[�T�C�Y��</param>
	/// <param name="texHeight">�e�N�X�`���[�T�C�Y����</param>
	static void CreateInscance(float length = 40, float height=20,int texWidth = 2048, int texHeight = 2048,int use_light=0);
	static CShadow* GetInstance(int idx=0);
	static void ClearInstance();
	CShadow(float length, float height,int texWidth, int texHeight,int use_light);
	~CShadow();
	void SetLightProjectionMatrix(CMatrix &m) {
		m_lightProj = m;
	}
	void SetLightViewMatrix(CMatrix &m) {
		m_lightView = m;
	}
	/// <summary>
	/// �e�t���`��
	/// </summary>
	/// <param name="render">���f����`�悷��֐�</param>
	/// <param name="gbuffer">�ŏI�I�ȕ`��悪����Ύw��</param>
	static void Render(std::function<void()> render, CTextureFrame* gbuffer=nullptr,bool update_shadow=true);
	static size_t GetListSize() {
		return m_shadow_list.size();
	}

	static int GetTextureSize() {
		return m_shadow_tex_cnt;
	}

	static int GetState() {
		return m_state;
	}
	static bool isDoShadow() {
		return m_state == eShadow;
	}
	static CMatrix* GetShadowMatrixPointer() {
		return m_shadowMatrix.data();
	}
	static int* GetShadowTexIdxPointer() {
		return m_depth_tex_idx.data();
	}
	static CVector2D* GetShadowInvTexSizePointer() {
		return m_depth_inv_tex_size.data();
	}
	static float GetShadowAmbient() {
		return m_shadow_ambient;
	}
	/// <summary>
	/// �e�̔Z����ݒ�
	/// </summary>
	/// <param name="s">(�Z1�`0�W)</param>
	/// <returns></returns>
	static void SetShadowAmbient(float s) {
		m_shadow_ambient = s;
	}
	friend class CShadow;
};