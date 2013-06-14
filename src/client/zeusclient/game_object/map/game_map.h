#ifndef GAME_MAP
#define GAME_MAP
#include "control/control_object/texture_object.h"
#include "globaldef.h"
#include "import\hge\include\hgeVector.h"
#include "import\hge\include\hgefont.h"

#include <string>
#include <vector>
using namespace std;

typedef hgeVector roleVector;

typedef unsigned long DWORD;
#define ACCURACY 8              ///ͨ��n�������ж���ײ

class CoveringTex
    : public TextureObject
{
public:
    
    bool Load(string texPath, float x, float y);

    void Render();

    CoveringTex() {}
    virtual ~CoveringTex() {}
private:
    float m_x;          ///����ڵ�ͼ������
    float m_y;          
};

class GameMap
{
public:
    
    GameMap();
    virtual ~GameMap();

    ///��ZeusMap�ļ��ж�ȡ��ͼ��Ϣ
    bool LoadFromZMap(string zMap);

    bool Load(string mapTex, string collisionMapTex);
    ///���Ƶ�ͼ

    void Render();

    ///�����ڸǽ�ɫ�Ĳ��� Ӧ���ڽ�ɫ����֮�����
    void RenderCovering();

    ///���������
    bool PushCovering(string path, float x, float y);

    ///�Ƴ�������
    void PopCovering();
    
    void PopCoveringAll();

    ///��ͼ���
    float GetWidth() { return m_mapTex->GetWidth();}
    
    ///��ͼ�߶�
    float GetHeight() { return m_mapTex->GetHeight();}

    //�ж��Ƿ����ײ����ͼ
    bool isCollision(roleVector v, int r, DWORD color);

private:
    TextureObject* m_mapTex;
    TextureObject* m_collisionMapTex;
    vector<CoveringTex*> m_coveringTex;
    roleVector m_previousPos;
};


#endif