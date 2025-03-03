#pragma once
enum {
    eType_Field,
    eType_Player,
    eType_Enemy,
    eType_Goal,
    eType_Player_Attack,
    eType_Enemy_Attack,
    eType_Effect,
    eType_Scene,
};

//�d�͉����x
#define GRAVITY (9.8f/20)
class Base {
public:
    int m_type;         //�I�u�W�F�N�g�̎��
    CVector2D m_pos;    //���W
    float m_rad;        //�����蔻��F�~���a
    CVector2D m_vec;    //�ړ��x�N�g��
    CRect   m_rect;     //��`
    bool m_kill;        //�폜�t���O
	//�X�N���[���l
    static CVector2D m_scroll;
    static std::list<Base*> m_list;     //�I�u�W�F�N�g���X�g
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Base(int type);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Base();
    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update();
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();
    /// <summary>
    /// �I�u�W�F�N�g�폜
    /// </summary>
    void SetKill() { m_kill = true; }
    /// <summary>
    /// �����蔻�茟��
    /// </summary>
    /// <param name="b">����Ώ�</param>
    virtual void Collision(Base* b);
    /// <summary>
    /// �~���m�̓����蔻��
    /// </summary>
    /// <param name="b1">�Ώ�1</param>
    /// <param name="b2">�Ώ�2</param>
    /// <returns></returns>
    static bool CollisionCircle(Base* b1, Base* b2);
    
    /// <summary>
    /// ��`���m�̓����蔻��
    /// </summary>
    /// <param name="b1">�Ώ�1</param>
    /// <param name="b2">�Ώ�2</param>
    /// <returns></returns>
    static bool CollisionRect(Base* b1, Base* b2);
    /// <summary>
    /// �����蔻���`�̃f�o�b�O�\��
    /// </summary>
    void DrawRect();


    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̍X�V
    /// </summary>
    static void UpdateAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̕`��
    /// </summary>
    static void DrawAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g���m�̑g�ݍ��킹�œ����蔻�茟��
    /// </summary>
    static void CollisionAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̍폜�`�F�b�N
    /// </summary>
    static void CheckKillAll();

    /// <summary>
    /// �I�u�W�F�N�g�����X�g�֒ǉ�
    /// </summary>
    /// <param name="b">�ǉ��I�u�W�F�N�g</param>
    static void Add(Base* b);
    
    /// <summary>
    /// �S�ẴI�u�W�F�N�g�폜
    /// </summary>
    static void KillAll();
    /// <summary>
    /// �I�u�W�F�N�g�̒T���A�擾
    /// </summary>
    /// <param name="type">�T���Ώۂ̎��</param>
    /// <returns>�ŏ��ɔ��������Ώێ�ނ̃I�u�W�F�N�g�̃|�C���^</returns>
    static Base* FindObject(int type);

    /// <summary>
    /// �I�u�W�F�N�g�̒T���A�擾(����)
    /// </summary>
    /// <param name="type">�T���Ώۂ̎��</param>
    /// <returns>�Ώێ�ނ̃I�u�W�F�N�z��</returns>
    static std::vector<Base*> FindObjects(int type);

    /// <summary>
    /// �X�N���[���l�����ʏ�ł̍��W���v�Z
    /// </summary>
    /// <param name="pos">�ϊ��Ώۍ��W</param>
    /// <returns>��ʏ�̈ʒu</returns>
    static CVector2D GetScreenPos(const CVector2D& pos);

};
