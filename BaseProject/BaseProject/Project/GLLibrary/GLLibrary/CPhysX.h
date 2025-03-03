#pragma once
#ifdef USE_PHYSX_LIB
#include "GL.h"



#include "PxPhysicsAPI.h"
#include "extensions/PxD6JointCreate.h"
#pragma comment(lib, "PhysX_64.lib")
#pragma comment(lib, "PhysXCommon_64.lib")
#pragma comment(lib, "PhysXCooking_64.lib")
#pragma comment(lib, "PhysXExtensions_static_64.lib")
#pragma comment(lib, "PhysXFoundation_64.lib")
#pragma comment(lib, "PhysXPvdSDK_static_64.lib")
#pragma comment(lib, "PhysXTask_static_64.lib")
#pragma comment(lib, "SceneQuery_static_64.lib")
#pragma comment(lib, "SimulationController_static_64.lib")

class CMatrix;
class CVector3D;
class CVector4D;
class CQuaternion;
class CPhysXActor;
struct SPhysCollisionData {
	CPhysXActor* actor;
};
class CPhysXActor {
public:
	/// <summary>
	/// �g���K�[�R�[���o�b�N
	/// </summary>
	/// <param name="coll"></param>
	virtual void onTriggerEnter(const SPhysCollisionData& coll){};
	/// <summary>
	/// �ڐG�R�[���o�b�N
	/// </summary>
	/// <param name="coll"></param>
	virtual void onCollisionEnter(const SPhysCollisionData& coll) {};
	//�������撲����
	virtual void onTriggerStay(const SPhysCollisionData& coll) {};
	virtual void onCollisionStay(const SPhysCollisionData& coll) {};
	virtual void onTriggerExit(const SPhysCollisionData& coll) {};
	virtual void onCollisionExit(const SPhysCollisionData& coll) {};
};
struct CPhysXCollisionCore {
	CPhysXActor* actor[2];
	SPhysCollisionData data[2];
};
class CPhysX {
	// PhysX���ŗ��p����A���P�[�^�[
	physx::PxDefaultAllocator m_defaultAllocator;
	// �G���[���p�̃R�[���o�b�N�ŃG���[���e�������Ă�
	physx::PxDefaultErrorCallback m_defaultErrorCallback;
	// ��ʃ��x����SDK(PxPhysics�Ȃ�)���C���X�^���X������ۂɕK�v
	physx::PxFoundation* m_pFoundation = nullptr;
	// ���ۂɕ������Z���s��
	physx::PxPhysics* m_pPhysics = nullptr;
	// �V�~�����[�V�������ǂ��������邩�̐ݒ�Ń}���`�X���b�h�̐ݒ���ł���
	physx::PxDefaultCpuDispatcher* m_pDispatcher = nullptr;
	// �V�~�����[�V���������Ԃ̒P�ʂ�Actor�̒ǉ��Ȃǂ������ōs��
	physx::PxScene* m_pScene = nullptr;


	
	static CPhysX* mp_instance;
public:
	CPhysX();
	~CPhysX();
	bool Init();
	void Update();
	physx::PxPhysics* GetPxPhysics() {
		return m_pPhysics;
	}
	physx::PxScene* GetScene() {
		return m_pScene;
	}
	static void CreateInstance();
	static void ClearInstance();
	static CPhysX* GetInstance();
};

extern physx::PxMat44 ToPxMat44(const CMatrix& mat);
extern physx::PxVec3 ToPxVec3(const CVector3D& vec3);
extern physx::PxVec4 ToPxVec4(const CVector4D& vec4);
extern physx::PxQuat ToPxQuat(const CQuaternion& quat);
extern physx::PxTransform ToPxTransform(const CVector3D& position, const CVector3D& rotation);
extern physx::PxTransform ToPxTransform(CVector3D& position, CQuaternion& quaternion);

extern CMatrix ToMatrix(const physx::PxMat44& px_mat44);
extern CVector3D ToVector3(const physx::PxVec3& px_vec3);
extern CVector4D ToVector4(const physx::PxVec4& px_vec4);
extern CQuaternion ToQuaternion(const physx::PxQuat& px_quat);
#endif