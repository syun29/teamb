#include "Task.h"
#include"TaskManager.h"

//�R���X�g���N�^
Task::Task(int prio,int sortOrder)
	:m_isEnable(true)
	,m_isShow(true)
	,m_isKill(false)
	,m_prio(prio)
	,m_sortOrder(sortOrder)
{
	//TaskManager�̃��X�g�Ɏ��g��ǉ�
	TaskManager::Instance()->Add(this);
}

//�f�X�g���N�^
Task::~Task()
{
	//TaskManager�̃��X�g���玩�g�����o��
	TaskManager::Instance()->Remove(this);
}

//�X�V
void Task::Update()
{
}

//�`��
void Task::Render()
{
}

//�L���t���O��ݒ�
void Task::SetEnable(bool enable)
{
	m_isEnable = enable;
}

//�L���t���O���擾
bool Task::IsEnable() const
{
	return m_isEnable;
}

//�\���t���O��ݒ�
void Task::SetShow(bool show)
{
	m_isShow = show;
}

//�\���t���O���擾
bool Task::IsShow() const
{
	return m_isShow;
}

//�^�X�N���폜
void Task::Kill()
{
	m_isKill = true;
}

//�폜�t���O�������Ă��邩
bool Task::IsKill() const
{
	return m_isKill;
}

//�D��x��ݒ�
void Task::SetPriority(int prio)
{
	m_prio = prio;
	//��x���X�g�����菜���āA�ēx�ǉ����Ȃ������Ƃŕ��ѕς���
	TaskManager::Instance()->Remove(this, true);
	TaskManager::Instance()->Add(this, true);
}

//�D��x���擾
int Task::GetPriority() const
{
	return m_prio;
}

//�D��x���̏��Ԃ�ݒ�
void Task::SetSortOrder(int order)
{
	m_sortOrder = order;
	//��x���X�g�����菜���āA�ēx�ǉ����Ȃ������Ƃŕ��ѕς���
	TaskManager::Instance()->Remove(this, true);
	TaskManager::Instance()->Add(this, true);
}

//�D��x���̏��Ԃ��擾
int Task::GetSortOrder() const
{
	return m_sortOrder;
}
