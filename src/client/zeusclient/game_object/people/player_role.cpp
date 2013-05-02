#include "globaldef.h"
#include "player_role.h"

PlayerRole::PlayerRole(float x, float y)
    : Role(x, y)
    , m_Direction(Direction_Up)
    , m_animation(NULL)
{
    m_animation = LoadRoleImage("res\\img\\self.png", 64, MOVEFRAMEMAX, 0, 0, 128, 128);
    m_nSpeed = 3;
}

PlayerRole::~PlayerRole()
{
}

void PlayerRole::SetViewport(roleVector v)
{
    m_viewportPos = v;
}

void PlayerRole::Render()
{
    if (!m_animation)
    {
        return;
    }
    /// ��������ת��Ϊ�ӿ����� ͬʱ��������㵽���Ͻ�
    m_animation->Render(
        (float)m_nPosX - m_viewportPos.x - m_nWidth / 2, 
        (float)m_nPosY - m_viewportPos.y - m_nHeight * 3 / 4); 
}


void PlayerRole::Update()
{
    if (!m_bMoving)///������ʱ��ָ��ŵĶ���
        m_animation->Play(int(m_Direction) * 8 + 1, int(m_Direction) * 8 + 1, true);

    m_bMoving  = false;
}

bool PlayerRole::IsVaild()
{
    return true;
}

roleVector PlayerRole::GetNextPos()
{
    roleVector nextPos(m_nPosX, m_nPosY);

    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) != Key_Down &&
        InputEngine_->IsKey(KEY_RIGHT) != Key_Down) ///������
    {
        m_Direction = Direction_Up;
        nextPos.y = m_nPosY - m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) != Key_Down &&
        InputEngine_->IsKey(KEY_RIGHT) != Key_Down) ///������
    {
        m_Direction = Direction_Down;
        nextPos.y = m_nPosY + m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_LEFT) == Key_Down && 
        InputEngine_->IsKey(KEY_DOWN) != Key_Down &&
        InputEngine_->IsKey(KEY_UP) != Key_Down) ///������
    {
        m_Direction = Direction_Left;
        nextPos.x = m_nPosX - m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_RIGHT) == Key_Down && 
        InputEngine_->IsKey(KEY_DOWN) != Key_Down &&
        InputEngine_->IsKey(KEY_UP) != Key_Down) ///������
    {
        m_Direction = Direction_Right;
        nextPos.x = m_nPosX + m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) == Key_Down) ///��������
    {
        m_Direction = Direction_LeftUp;
        nextPos.x = m_nPosX - 0.707f * m_nSpeed; /// cos45�� = 0.707
        nextPos.y = m_nPosY - 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_UP) == Key_Down && 
        InputEngine_->IsKey(KEY_RIGHT) == Key_Down) ///��������
    {
        m_Direction = Direction_RightUp;
        nextPos.x = m_nPosX + 0.707f * m_nSpeed; /// cos45�� = 0.707
        nextPos.y = m_nPosY - 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_LEFT) == Key_Down) ///��������
    {
        m_Direction = Direction_LeftDown;
        nextPos.x = m_nPosX - 0.707f * m_nSpeed; /// cos45�� = 0.707
        nextPos.y = m_nPosY + 0.707f * m_nSpeed;
    }
    if (InputEngine_->IsKey(KEY_DOWN) == Key_Down && 
        InputEngine_->IsKey(KEY_RIGHT) == Key_Down) ///��������
    {
        m_Direction = Direction_RightDown;
        nextPos.x = m_nPosX + 0.707f * m_nSpeed; /// cos45�� = 0.707
        nextPos.y = m_nPosY + 0.707f * m_nSpeed;
    }
    if (m_Direction != m_LastDir)
    {
        m_animation->Stop();
        m_animation->Play(int(m_Direction) * 8 + 1, int(m_Direction) * 8 + 9, true);
    }    
    m_LastDir = m_Direction;
    return nextPos;
}

RollBorder PlayerRole::IsRollBorder()
{
    if ((WINDOW_WIDTH - ROLLBODERSPACE) <= m_nPosX)
    {
        return Border_Right;
    }
    else if ((WINDOW_HEIGHT - ROLLBODERSPACE) <= m_nPosY)
    {
        return Border_Bottom;
    }
    else if (m_nPosX <= ROLLBODERSPACE)
    {
        return Border_Left;
    }
    else if (m_nPosY <= ROLLBODERSPACE)
    {
        return Border_Top;
    }
    return Border_NULL;
}

void PlayerRole::MoveTo(roleVector v)
{
    if (m_nPosX != v.x || m_nPosY != v.y)
    {
        m_nPosX = v.x;
        m_nPosY = v.y;
        m_bMoving  = true;
    }
}

int PlayerRole::GetAreaRadins()
{
    return m_nWidth / 16; ///������ռ����İ뾶 ��������Ĵ�С����ͬ �� ������ͼ����й�
}

void PlayerRole::Stop()
{
    m_bMoving = false;
}

roleVector PlayerRole::GetPos()
{
    roleVector v(m_nPosX, m_nPosY);
    return v;
}