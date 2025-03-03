#pragma once
#include "../Base/Base.h"

class Enemy : public Base {

private:
    //���
    enum {
        eState_Idle,
        eState_Attack,
        eState_Damage,
        eState_Down,
    };
    int m_state;        //���
    CImage m_img;       //�摜
    bool	m_flip;     //���]
    bool m_is_ground;   //���n�t���O
    //�U���ԍ�
    int m_attack_no;
    //�_���[�W�ԍ�
    int m_damage_no;
    //�q�b�g�|�C���g
    int m_hp;
    void StateIdle();
    void StateAttack();
    void StateDamage();
    void StateDown();
public:
    Enemy(const CVector2D& p, bool flip);
    void Update();
    void Draw();
    void Collision(Base* b);
};