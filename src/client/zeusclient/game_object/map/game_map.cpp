#include "game_map.h"
#include <math.h>
#include "control\pool\picture_pool.h"
#include "game_object\viewport\viewport.h"
bool CoveringTex::Load(string texPath, float x, float y)
{
    if (TextureObject::Load(texPath))
    {
            m_x = x;
            m_y = y;
            return true;
    }
    else //Loadʧ��
    {
        return false;
    }
}
void CoveringTex::Render()
{
    ///��ͨ������ü��ڸ�ͼƬ����Ļ��
    float x = 0,y = 0;
    float tx = 0,ty = 0;
    float w = 0,h = 0;
    viewportVector v = Viewport::Instance()->GetPos();
    x = m_x - (int)v.x;        //����Ļ�ϵ�����
    y = m_y - (int)v.y;
    tx = -x;                        //��������������
    ty = -y;
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if (tx < 0)
        tx = 0;
    if (ty < 0)
        ty = 0;
    w = GetWidth() - tx;
    h = GetHeight() - ty;
    if (tx > GetWidth())
        w = 0;
    if (ty > GetHeight())
        h = 0;

    if (w > 0 && h > 0)
    {
        TextureObject::SetRenderRect(tx, ty, w, h);
        TextureObject::Render(x, y);
    }
}

GameMap::GameMap()
    : m_mapTex(NULL)
    , m_collisionMapTex(NULL)
    , m_previousPos(0, 0)
{
}
bool GameMap::Load(string mapTex, string collisionMapTex)
{
    m_mapTex = PicturePool::Instance()->Get(mapTex);
    m_collisionMapTex = PicturePool::Instance()->Get(collisionMapTex);
    if (!m_mapTex)
    {
        return false;
    }
    if (!m_collisionMapTex)
    {
        return false;
    }
    return true;
}
GameMap::~GameMap()
{
    for (int i = 0; i < (int)m_coveringTex.size(); i++)
    {
        delete m_coveringTex[i];
    }
}

void GameMap::Render()
{
    if (!m_mapTex)
    {
        return;
    }
    viewportVector v = Viewport::Instance()->GetPos();
    if (v.x <  0)
        v.x = 0;

    if (v.x > m_mapTex->GetWidth() - WINDOW_WIDTH)
        v.x =  m_mapTex->GetWidth() - WINDOW_WIDTH;

    if (v.y <  0)
        v.y = 0;

    if (v.y > m_mapTex->GetHeight() - WINDOW_HEIGHT)
        v.y = m_mapTex->GetHeight() - WINDOW_HEIGHT;
    Viewport::Instance()->SetPos(v.x, v.y);
    m_mapTex->SetRenderRect(v.x, v.y, WINDOW_WIDTH, WINDOW_HEIGHT);
    m_mapTex->Render(0, 0);
}

///�����ڸǽ�ɫ�Ĳ��� Ӧ���ڽ�ɫ����֮�����
void GameMap::RenderCovering()
{
    for (int i = 0; i < (int)m_coveringTex.size(); i++)
    {
        m_coveringTex[i]->Render();
    }
}

///���������
bool GameMap::PushCovering(string path, float x, float y)
{
    CoveringTex* tex = new CoveringTex;
    if (!tex->Load(path, x, y))
    {
        delete tex;
        return false;
    }
    m_coveringTex.push_back(tex);
    return true;

}

///�Ƴ�������
void GameMap::PopCovering()
{
    if (m_coveringTex.size() > 0)
    {
        m_coveringTex.pop_back();
    }
}

    
void GameMap::PopCoveringAll()
{
    if (m_coveringTex.size() > 0)
    {
        m_coveringTex.clear();
    }
}

bool GameMap::isCollision(roleVector nextPos, 
                          int r, ///��λ��ռ����İ뾶
                          DWORD color ///��ײ����ɫ
                          )
{
    if (!m_mapTex)
    {
        return false;
    }
    if (!m_collisionMapTex)
    {
        return false;
    }
    for (int i = 0; i < ACCURACY; i++)
    {
        DWORD* pClr = m_collisionMapTex->CheckColor(
            nextPos.x + sin(2 * PI * i / ACCURACY) * r, 
            nextPos.y + cos(2 * PI * i / ACCURACY) * r, 1, 1);
        if (!pClr)
        {
            return true;
        }
        if (*pClr == color)
        {
            return true;
        }
    }
    return false;
}