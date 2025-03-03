#pragma once
#include "GL.h"
#include "CMatrix.h"
#include "CRect.h"
#include<list>
class CCamera;
class COBB;
namespace Utility {
	/*!
		@brief	Degree�i�x�j��Radian�ɕϊ�
		@param	d				[in] �p�x
		@retval	Radian�ɕϊ����ꂽ�p�x
	**/

	inline float DgreeToRadian(float d) {
		return (float)(d*M_PI / 180.0f);
	}
	inline float RadianToDgree(float d) {
		return (float)(d *180.0f/ M_PI);
	}
	/*!
		@brief	�p�x�̐��K��
		@param	a				[in] �p�x
		@retval	-PI�`PI
	**/

	inline float NormalizeAngle(float a) {
		if (a>M_PI) return (float)(a - M_PI * 2);
		else if (a<-M_PI) return (float)(a + M_PI * 2);
		return a;
	}
	/*!
		@brief	�����擾
		@param	min				[in] �Œ�l
		@param	max				[in] �ő�l
		@retval	�Œ�l�`�ő�l�̗���
	**/

	inline int Rand(int min,int max) {
		return min + rand()% ((max - min)+1);
	}
	inline float Rand(float min, float max) {
		return min + ((max - min) * rand() / RAND_MAX);
	}
	inline float Lerp(float start, float end, float t) {
		return start + t * (end - start);
	}
	inline int Clamp(int v, int low, int high) {
		return min(max(v, low), high - 1);
	}
	inline float Clamp(float v, float low, float high) {
		return min(max(v, low), high);
	}
	inline float Clamp01(float v) {
		return Clamp(v, 0.0f, 1.0f);
	}

	/*!
		@brief	�X�N���[�����W�ϊ������[���h���W
		@param	spos			[in] �X�N���[�����W
		@param	mProj			[in] �ˉe�s��
		@param	mView			[in] �r���[�s��
		@param	viewport		[in] �r���[�|�[�g��`
		@retval	���[���h���W
	**/
	CVector3D ScreenToWorld(const CVector3D& spos, const CMatrix& mProj, const CMatrix& mView, const CRect& viewport);

	/*!
	@brief	�X�N���[�����W�ϊ������[���h���W
	@param	spos			[in] �X�N���[�����W
	@param	camera			[in] �g�p�J����
	@retval	���[���h���W
	**/
	CVector3D ScreenToWorld(const CVector3D& spos, const CCamera* camera);
	CVector3D ScreenToWorld(const CVector3D& spos);
	/*!
		@brief	���[���h���W���X�N���[�����W�ϊ�
		@param	wpos			[in] ���[���h���W
		@param	mProj			[in] �ˉe�s��
		@param	mView			[in] �r���[�s��
		@param	viewport		[in] �r���[�|�[�g��`
		@retval	�X�N���[�����W
	**/
	CVector3D WorldToScreen(const CVector3D& wpos, const CMatrix& mProj, const CMatrix& mView, const CRect& viewport);
	/*!
	@brief	���[���h���W���X�N���[�����W�ϊ�
	@param	out				[out] �X�N���[�����W
	@param	wpos			[in] ���[���h���W
	@param	camera			[in] �g�p�J����
	**/
	CVector3D WorldToScreen(const CVector3D& wpos, const CCamera* camera);
	CVector3D WorldToScreen(const CVector3D& wpos);
	/*!
	@brief	��������
	@param	s				[in] �����̎n�_
	@param	e				[in] �����̏I�_
	@param	color			[in] �F
	@retval	����
	**/
	void DrawLine(const CVector2D &s, const CVector2D &e, const CVector4D &color);

	void DrawQuad(const CVector2D &pos, const CVector2D &size, const CVector4D &color);


	void DrawLine(const CVector3D &s, const CVector3D &e, const CVector4D &color,float lineWidth=1.0);
	void DrawCube(const CVector3D &pos, const float size, const CVector4D &color);
	void DrawCube(const CVector3D& pos, const CVector3D& size, const CVector4D& color);
	void DrawAABB(const CVector3D& min, const CVector3D& max, const CVector4D& color);
	void DrawCube(const CMatrix &mat, const CVector4D &color);
	void DrawSphere(const CVector3D &pos, const float size, const CVector4D &color);
	void DrawSphere(const CMatrix &mat, const float size, const CVector4D &color);
	void DrawCircle(const CVector2D &pos, const float size, const CVector4D &color);
	void DrawCapsule(const CVector3D &s, const CVector3D &e, const float rad, const CVector4D &color);
	void DrawCapsule(const CVector2D& s, const CVector2D& e, const float size, const CVector4D& color);
	void DrawArrow(const CVector3D& pos, const CVector3D& rot, const float size, const CVector4D& color);
	void DrawArrow(const CVector2D& pos, const float ang, const float size, const CVector4D& color);
	void DrawOBB(const COBB& obb, const CVector4D& color);
	void DrawTriangle(const CVector3D vertex[], int count, const CVector4D& color, const CMatrix& mat);
	void DrawQuad(const CVector3D vertex[], int count, const CVector4D& color, const CMatrix& mat);
	void DrawCircle(const CVector2D vertex[], const int count,const CVector2D& pos, const CVector4D& color);
	void DrawSector(const CMatrix& mat, const float start, const float end, const float size, const CVector4D& color);

	/// <summary>
	/// �Ȃ߂炩�ȉ~��\��
	/// </summary>
	/// <param name="pos">�\���ʒu</param>
	/// <param name="size">�~�̑傫��</param>
	/// <param name="color">�F</param>
	void DrawSmoothCircle(const CVector3D& pos, const float size, const CVector4D& color);

	//�����œn���ꂽ�Ώۂƃ}�E�X�J�[�\���̓����������W
	template <typename T>
	CVector3D GetCrossSingle(T* target) {
		//�}�E�X�̍��W(�X�N���[�����W)
		CVector3D MousePos = CInput::GetMousePoint();
		//�����̒��������߂�
		float dist = 0.99f;
		//�X�N���[�����W�����[���h���W�ɕϊ�
		//�����Ɏg���ϐ�(�n�_�ƏI�_)
		//���[���h���W ��
		CVector3D Mouse_W_near = Utility::ScreenToWorld(CVector3D(MousePos.x, MousePos.y, 0.0f));
		//���[���h���W ��
		CVector3D Mouse_W_far = Utility::ScreenToWorld(CVector3D(MousePos.x, MousePos.y, dist));

		//�}�E�X�̃��[���h���W�߂��烏�[���h���W���ւ̐��� �� �t�B�[���h���f���Ƃ̓����蔻��
		//�ڐG�_�Ɩ@��
		CVector3D cross, normal;
		//�^�[�Q�b�g�����݂��Ă��邩�A�^�[�Q�b�g�ƃ��C�̓����蔻�肪���������ꍇ
		if (target && target->GetModel()->CollisionRay(&cross, &normal, Mouse_W_near, Mouse_W_far)) {
			return cross;
		}
		//�l���擾�ł��Ȃ������ꍇ�A0��Ԃ�
		return CVector3D::zero;
	}

	//�����œn���ꂽ���X�g���̑Ώۂƃ}�E�X�J�[�\���̓����������W��ԋp
	template <typename T>
	static CVector3D GetCrossMultiple(const std::list<T*>& targetList) {
		//�}�E�X�̍��W(�X�N���[�����W)
		CVector3D MousePos = CInput::GetMousePoint();
		//�����̒��������߂�
		float dist = 0.99f;
		//�X�N���[�����W�����[���h���W�ɕϊ�
		//�����Ɏg���ϐ�(�n�_�ƏI�_)
		//���[���h���W ��
		CVector3D Mouse_W_near = Utility::ScreenToWorld(CVector3D(MousePos.x, MousePos.y, 0.0f));
		//���[���h���W ��
		CVector3D Mouse_W_far = Utility::ScreenToWorld(CVector3D(MousePos.x, MousePos.y, dist));

		//�}�E�X�̃��[���h���W�߂��烏�[���h���W���ւ̐��� �� �t�B�[���h���f���Ƃ̓����蔻��
		//�ڐG�_�Ɩ@��
		CVector3D cross, normal;
		//�^�[�Q�b�g�����݂��Ă��邩�A�^�[�Q�b�g�ƃ��C�̓����蔻�肪���������ꍇ
		for (auto& target : targetList) {
			if (target && target->GetModel()->CollisionRay(&cross, &normal, nearPos, farPos)) {
				return cross;
			}
		}
		//�l���擾�ł��Ȃ������ꍇ�A0��Ԃ�
		return CVector3D::zero;
	}
}

#define RtoD(x) Utility::RadianToDgree(x)
#define DtoR(x) Utility::DgreeToRadian(x)