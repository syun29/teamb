#include "TaskManager.h"
#include"Task.h"
#include"ObjectBase.h"

//TaskManager�̃C���X�^���X�̐ÓI�ȃ����o�ϐ����`
TaskManager* TaskManager::ms_instance = nullptr;

//�R���X�g���N�^
TaskManager::TaskManager()
{

}

//�f�X�g���N�^
TaskManager::~TaskManager()
{
}
//TaskManager�̃C���X�^���X���擾
TaskManager* TaskManager::Instance()
{
	//�C���X�^���X����������ĂȂ���΁A
	//�C���X�^���X������ɕԂ�
	if (ms_instance == nullptr)
	{
		ms_instance=new TaskManager();
	}
	return ms_instance;
}
//TaskManager�̃C���X�^���X��j��
void TaskManager::ClearInstance()
{
	//�C���X�^���X����������Ă�����A�폜����
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//�^�X�N���X�g�Ƀ^�X�N��ǉ�
void TaskManager::Add(Task* task, bool sort)
{
	//���ѕς����̒ǉ������łȂ����
	if (!sort)
	{
		//�ǉ������^�X�N���I�u�W�F�N�g�ł���΁A
		//�I�u�W�F�N�g���X�g�ɂ��ǉ�
		if (task->m_prio == (int)ETaskPrio::Object)
		{
			m_objectList.push_back(task);
		}
	}

	auto itr = m_taskList.begin();
	auto end = m_taskList.end();
	while (itr != end)
	{
		Task* curr = *itr;
		//�ǉ�����^�X�N�̗D��x�̒l�̕����������ꍇ�́A
		//���̈ʒu�Ƀ^�X�N��ǉ�����
		if (task->m_prio < curr->m_prio)
		{
			m_taskList.insert(itr, task);
			return;
		}
		//�ǉ�����^�X�N�ƌ��ݒ��ׂĂ���^�X�N�̗D��x�������ꍇ�́A
		//m_sortOrder�̏��ԂŃ��X�g�ɒǉ�����
		else if (task->m_prio == curr->m_prio)
		{
			if (task->m_sortOrder < curr->m_sortOrder)
			{
				m_taskList.insert(itr, task);
				return;
			}
		}
		++itr;
	}
	//���X�g�̊Ԃɒǉ�����ꏊ��������Ȃ������̂ŁA
	//���X�g�̈�ԍŌ�ɒǉ�
	m_taskList.push_back(task);
}

//�^�X�N���X�g����^�X�N����菜��
void TaskManager::Remove(Task* task, bool sort)
{
	//���ёւ����łȂ����
	if (!sort)
	{
		//�I�u�W�F�N�g�̃��X�g�������菜��
		if (task->m_prio == (int)ETaskPrio::Object)
		{
			m_objectList.remove(task);
		}
	}

	m_taskList.remove(task);
}

 //���ׂẴ^�X�N���폜
void TaskManager::DeleteAll()
 {
	//�I�u�W�F�N�g�̃��X�g����ɂ���
	m_objectList.clear();

	 //�^�X�N���X�g�̐擪���珇�Ԃɍ폜����
	 auto itr = m_taskList.begin();
	 auto end = m_taskList.end();
	 while(itr != end)
	 {
		 //�폜����^�X�N�̃A�h���X����U�L�����A
		 //���X�g�����菜������ɁA�^�X�N���폜����
		 Task* del = *itr;
		 itr = m_taskList.erase(itr);
		 delete del;
	 }
 }
 //�폜�t���O�������Ă���^�X�N���폜
 void TaskManager::DeleteKilledTasks()
 {
	 auto itr = m_taskList.begin();
	 auto end = m_taskList.end();
	 while (itr != end)
	 {
		 //�폜�t���O�������Ă�����A�폜����
		 Task* task = *itr;
		 if (task-> IsKill())
		 {
			 Task* del = *itr;
			 itr = m_taskList.erase(itr);
			 delete del;
		 }
		 //�폜�t���O�������Ă��Ȃ���΁A�l���̃^�X�N�𒲂ׂ�
		 else
		 {
			 ++itr;
		 }
	 }
 }

 //���X�g�ɓo�^����Ă���^�X�N���X�V
 void TaskManager::Update()
 {
	 //���X�g�̐擪���珇�ԂɍX�V�������Ăяo��
	 for (Task* task : m_taskList)
	 {
		 //�^�X�N���L���ł���΁A�X�V
		 if(task->IsEnable())
		 { 
		 task->Update();
		 }
	 }
 }

 //���X�g�ɓo�^����Ă���^�X�N��`��
 void TaskManager::Render()
 {
	 //�I�u�W�F�N�g���X�g�̒��g�����s�̍��W���傫�����ɕ��ׂ�
	 m_objectList.sort
	 (
		 [](const Task* task0, const Task* task1)
		 {
			 const ObjectBase* obj0 = dynamic_cast<const ObjectBase*>(task0);
			 const ObjectBase* obj1 = dynamic_cast<const ObjectBase*>(task1);
			 return obj0->GetPos().z < obj1->GetPos().z;
		 }
	 );

	 //���ѕς����I�u�W�F�N�g���X�g�̐擪���珇�Ԃ�
	 //SortOrder�̒l��ݒ�
	 int sortOrder = 0;
	 for (Task* obj : m_objectList)
	 {
		 obj->SetSortOrder(sortOrder);
		 sortOrder++;
	 }
	 //���X�g�̐擪���珇�Ԃɕ`�揈�����Ăяo��
	 for (Task* task : m_taskList)
	 {
		 //�^�X�N���L�����A�\����ԂȂ�΁A�`��
		 if(task->IsEnable()&&task->IsShow())
		 { 
		 task->Render();
		 }
	 }
 }
