#pragma once

class TaskManager;
enum {
	eType_Enemy,
	eType_Player,
	eType_Star,
	eType_Field,
};
//�^�X�N�̗D��x�̎��
enum class ETaskPrio
{
	Field, //�t�B�[���h
	Nomal,
	Shadow, //�e
	Object, //�I�u�W�F�N�g�i�v���C���[�Ƃ��G�Ƃ��j
	UI,
};
class Task
{
	friend TaskManager;

public:
	//�R���X�g���N�^
	Task(int prio,int sortOrder,int type);
	//�f�X�g���N�^
	virtual ~Task();

	//�X�V
	virtual void Update();
	//�`��
	virtual void Render();

	virtual void Collision(Task*b);
	static void CollisionCube(Task*b1,Task*b2);

	
	//�L���t���O��ݒ�
	void SetEnable(bool enable);
	//�L���t���O���擾
	bool IsEnable() const;

	//�\���t���O��ݒ�
	void SetShow(bool show);
	//�\���t���O���擾
	bool IsShow() const;

	//�^�X�N���폜
	void Kill();
	//�폜�t���O�������Ă��邩
	bool IsKill() const;

	//�D��x��ݒ�
	void SetPriority(int prio);
	//�D��x���擾
	int GetPriority() const;

	//�D��x���̏��Ԃ�ݒ�
	void SetSortOrder(int order);
	//�D��x���̏��Ԃ��擾
	int GetSortOrder() const;
	
private:
	bool m_isEnable; //�L���t���O
	bool m_isShow; //�\���t���O
	bool m_isKill; //�폜�t���O
	int m_prio; //�D��x
	int m_sortOrder; //�����D��x���ł̏���
	int m_type;
};