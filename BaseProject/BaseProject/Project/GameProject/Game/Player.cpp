#include "Player.h"
#include "AnimData.h"
#include "Field.h"
#include "Slash.h"
#include "Effect.h"
Player::Player(const CVector2D& p, bool flip) :
    Base(eType_Player) {
    //�摜����
    m_img = COPY_RESOURCE("Player", CImage);
    //�Đ��A�j���[�V�����ݒ�
    m_img.ChangeAnimation(0);
    //���W�ݒ�
    m_pos = p;
    //���S�ʒu�ݒ�
    m_img.SetCenter(128, 224);
    //���]�t���O
    m_flip = flip;
    //�ʏ��Ԃ�
    m_state = eState_Idle;
    //���n�t���O
    m_is_ground = true;
    //�U���ԍ�
    m_attack_no = rand();
    //�_���[�W�ԍ�
    m_damage_no = -1;
    //�q�b�g�|�C���g
    m_hp = 100;



}
void Player::StateIdle()
{
    //�ړ���
    const float move_speed = 6;
    //�ړ��t���O
    bool move_flag = false;
    //���ړ�
    if (HOLD(CInput::eLeft)) {
        //�ړ��ʂ�ݒ�
        m_pos.x += -move_speed;
        //���]�t���O
        m_flip = true;
        move_flag = true;
    }
    //�E�ړ�
    if (HOLD(CInput::eRight)) {
        //�ړ��ʂ�ݒ�
        m_pos.x += move_speed;
        //���]�t���O
        m_flip = false;
        move_flag = true;
    }
    //�U��
    if (PUSH(CInput::eButton1)) {
        //�U����Ԃֈڍs
        m_state = eState_Attack;
        m_attack_no++;
    }
    //�W�����v��
    const float jump_pow = 12;

    //�W�����v
    if (m_is_ground && PUSH(CInput::eButton2)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
    }


    //�W�����v���Ȃ�
    if (!m_is_ground) {
        if (m_vec.y < 0)
            //�㏸�A�j���[�V����
            m_img.ChangeAnimation(eAnimJumpUp, false);
        else
            //���~�A�j���[�V����
            m_img.ChangeAnimation(eAnimJumpDown, false);
    }
    //�n�ʂɂ���Ȃ�
    else
    {
        if (move_flag) {
            //����A�j���[�V����
            m_img.ChangeAnimation(eAnimRun);
        } else {
            //�ҋ@�A�j���[�V����
            m_img.ChangeAnimation(eAnimIdle);
        }
    }


}
void Player::StateDuck()
{

    //�����蔻��p��`�ݒ�
    m_rect = CRect(-32, -64, 32, 0);
    //���Ⴊ�݃A�j���[�V����
    m_img.ChangeAnimation(eAnimDuck);
    //�{�^���𗣂��Βʏ��Ԃ�
    if (FREE(CInput::eDown))
        m_state = eState_Idle;
}

void Player::StateAttack()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
            Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
        }
        else {
            Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
        }
    }
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
        m_state = eState_Idle;
    }

}
void Player::StateDamage()
{
    m_img.ChangeAnimation(eAnimDamage, false);
    if (m_img.CheckAnimationEnd()) {
        m_state = eState_Idle;
    }
}
void Player::StateDown()
{
    m_img.ChangeAnimation(eAnimDown, false);
    if (m_img.CheckAnimationEnd()) {
        Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
        m_kill = true;
    }
}


void Player::Update() {
    switch (m_state) {
    //�ʏ���
    case eState_Idle:
        StateIdle();
        break;
    //���Ⴊ�ݏ��
    case eState_Duck:
        StateDuck();
        break;
        //�U�����
    case eState_Attack:
        StateAttack();
        break;
        //�_���[�W���
    case eState_Damage:
        StateDamage();
        break;
        //�_�E�����
    case eState_Down:
        StateDown();
        break;
    }
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    //�A�j���[�V�����X�V
    m_img.UpdateAnimation();
    m_scroll.x = m_pos.x - 1280 / 2;
   // m_scroll.y = m_pos.y - 720 / 2;
}
void Player::Draw() {
    //�ʒu�ݒ�
    m_img.SetPos(GetScreenPos(m_pos));
    //���]�ݒ�
    m_img.SetFlipH(m_flip);
    //�`��
    m_img.Draw();
}
void Player::Collision(Base* b)
{
    switch (b->m_type) {
    //�S�[���Ƃ̓����蔻��i��`�̔���j
    case eType_Goal:
        //������΃S�[�����폜
        if (Base::CollisionRect(this, b)) {
            b->SetKill();
        }
        break;
        //�U���I�u�W�F�N�g�Ƃ̔���
    case eType_Enemy_Attack:
        //Slash�^�փL���X�g�A�^�ϊ��ł�����
        if (Slash* s = dynamic_cast<Slash*>(b)) {
            if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
                m_damage_no = s->GetAttackNo();
                m_hp -= 50;
                if (m_hp <= 0) {
                    m_state = eState_Down;
                }
                else {
                    m_state = eState_Damage;
                }
                Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
            }
        }
        break;
    case eType_Field:
        //Field�^�փL���X�g�A�^�ϊ��ł�����
        if (Field* f = dynamic_cast<Field*>(b)) {
            //�n�ʂ�艺�ɂ�������
            float y = f->GetGroundY(m_pos.x);
            if (m_pos.y > y) {
                //�n�ʂ̍����ɖ߂�
                m_pos.y = y;
                //�������x���Z�b�g
                m_vec.y = 0;
                //�ڒn�t���OON
                m_is_ground = true;
            }
        }
        break;
    }

}





