#include "Base.h"
std::list<Base*> Base::m_list;
//�X�N���[���l�̒�`
CVector2D Base::m_scroll(0, 0);
Base::Base(int type) : m_type(type),m_pos(0, 0),m_vec(0,0),m_rad(0), m_kill(false)
{
    //�R���X�g���N�^
    //�I�u�W�F�N�g�������ɌĂяo�����
    //�������������L�q
}

Base::~Base()
{

}

void Base::Update()
{
    //�X�V����
    //�h����ŋL�q
}

void Base::Draw()
{
    //�`�揈��
    //�h����ŋL�q
}
void Base::Collision(Base* b)
{
    //�����蔻��̌���
    //�h����ŋL�q
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
    //b2����b1�ւ̃x�N�g��
    CVector2D v = b1->m_pos - b2->m_pos;
    //�x�N�g���̑傫���Bb1-b2�̋����B
    float l = v.Length();
    //b1-b2�̋����ƁAb1,b2�̔��a�̍��Z�l�Ƃ̔�r�ŏՓˌ���
    if (l < b1->m_rad + b2->m_rad) {
        return true;
    }
    return false;
}
bool Base::CollisionRect(Base* b1, Base* b2)
{
    //b1�̋�`
    CRect rect1 = CRect(
        b1->m_pos.x + b1->m_rect.m_left,
        b1->m_pos.y + b1->m_rect.m_top,
        b1->m_pos.x + b1->m_rect.m_right,
        b1->m_pos.y + b1->m_rect.m_bottom);
    //b2�̋�`
    CRect rect2 = CRect(
        b2->m_pos.x + b2->m_rect.m_left,
        b2->m_pos.y + b2->m_rect.m_top,
        b2->m_pos.x + b2->m_rect.m_right,
        b2->m_pos.y + b2->m_rect.m_bottom);

    //��`���m�̔���
    if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
        rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top)
        return true;

    return false;
}
void Base::DrawRect()
{
    //�f�o�b�O�p�@��`�̕\��
    CRect rect = CRect(
        m_pos.x + m_rect.m_left,
        m_pos.y + m_rect.m_top,
        m_pos.x + m_rect.m_right,
        m_pos.y + m_rect.m_bottom);
    Utility::DrawQuad(
        CVector2D(rect.m_left, rect.m_top) - m_scroll,
        CVector2D(rect.m_width, rect.m_height),
        CVector4D(1, 0, 0, 0.5f));
}
void Base::CollisionAll()
{
    //�擪�̗v�f�̃|�C���^
    auto it1 = m_list.begin();
    //�����̗v�f�̃|�C���^
    auto last = m_list.end();
    //�������w���܂ŌJ��Ԃ�
    while (it1 != last) {
        //it2��it1�̎��̗v�f
        auto it2 = it1;
        it2++;
        //�S�Ă̑g�ݍ��킹�ŏՓˌ���
        while (it2 != last) {
            (*it1)->Collision(*it2);
            (*it2)->Collision(*it1);
            //���̗v�f��
            it2++;
        }
        //���̗v�f��
        it1++;
    }
}


void Base::UpdateAll()
{
    //���X�g���S�Ă̗v�f�̍X�V
    for (auto& b : m_list) {
        b->Update();
    }
}

void Base::DrawAll()
{
    //���X�g���S�Ă̗v�f�̕`��
    for (auto& b : m_list) {
        b->Draw();
    }
}

void Base::CheckKillAll()
{
    //�擪���疖���܂ŌJ��Ԃ���
    //�폜�Ώۂ����X�g����폜
    auto it = m_list.begin();
    auto last = m_list.end();
    while (it != last) {
        if ((*it)->m_kill) {
            delete (*it);
            //���X�g���珜�O
            it = m_list.erase(it);
        }
        else {
            //����
            it++;
        }
    }
}


void Base::Add(Base* b)
{
    //Type���ɂ��\�[�g
    auto itr = m_list.begin();
    while (itr != m_list.end()) {
        if ((*itr)->m_type > b->m_type) {
            m_list.insert(itr, b);
            return;
        }
        itr++;
    }
    //���X�g�̖����֒ǉ�
    m_list.push_back(b);
}

void Base::KillAll()
{
    for (auto& b : m_list)
        b->SetKill();
}

Base* Base::FindObject(int type)
{
    //���X�g�̐擪���疖���܂ŌJ��Ԃ�
    //type����v����I�u�W�F�N�g��ԋp����
    for (auto& b : m_list) {
        if (b->m_type == type) {
            //�������I�u�W�F�N�g�̕ԋp
            return b;
        }
    }
    return nullptr;
}

std::vector<Base*> Base::FindObjects(int type)
{
    std::vector<Base*> ret;
    //���X�g�̐擪���疖���܂ŌJ��Ԃ�
    //type����v����I�u�W�F�N�g�z���ԋp����
    for (auto& b : m_list) {
        if (b->m_type == type) {
            //�������I�u�W�F�N�g��ǉ�
            ret.push_back(b);
        }
    }
    return ret;
}

CVector2D Base::GetScreenPos(const CVector2D& pos)
{
    //���W-�X�N���[���l=��ʏ�ł̈ʒu
    return pos - m_scroll;

}

