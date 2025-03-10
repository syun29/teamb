#pragma once

class Task;
class ObjectBase;

 //�^�X�N���Ǘ�����^�X�N
class TaskManager
{
public:
	//TaskManager�̃C���X�^���X���擾
	static TaskManager* Instance();
	//TaskManager�̃C���X�^���X��j��
	static void ClearInstance();

	//�^�X�N���X�g�Ƀ^�X�N��ǉ�
	void Add(Task* task, bool sort = false);
	//�^�X�N���X�g����^�X�N����菜��
	void Remove(Task* task, bool sort = false);

	//�S�Ẵ^�X�N���폜
	void DeleteAll();
	//�폜�t���O�������Ă���^�X�N���폜
	void DeleteKilledTasks();

	//���X�g�ɓo�^����Ă���^�X�N���X�V
	void Update();
	//���X�g�ɓo�^����Ă���^�X�N��`��
	void Render();
	
	CVector3D m_max;
	CVector3D m_min;
	CVector3D m_pos;

	void AaBb(CVector3D max,CVector3D min,CVector3D pos,Task*b1,Task*b2);
	
	//void Collision();
	//void CollisionCircle();
	void Collision();
	/*CAABB m_max;
	CAABB m_min;*/
private:

	//�R���X�g���N�^
	TaskManager();
	//�f�X�g���N�^
	~TaskManager();


	//TaskManager�̃C���X�^���X
	static TaskManager* ms_instance;
	//�����ς݂̃^�X�N�̃��X�g
	std::list<Task*>m_taskList; 
	//�����ς݂̃I�u�W�F�N�g�̃��X�g
	std::list<Task*>m_objectList;
};