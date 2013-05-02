#ifndef TEXTURE_
#define TEXTURE_

#include "import\hge\include\hge.h"

#include <string>

class TextureObject
{
public:
    TextureObject();
    virtual ~TextureObject();

    virtual bool Load(const std::string& strPath);

    float GetWidth() const { return m_texWidth; }

    float GetHeight() const { return m_texHeight; }

    DWORD* CheckColor(float x, float y, int cx, int cy);
    
    void SetRenderRect(float tx, float ty, float width, float height);

    virtual void Render(float x, float y);

    virtual void Release();


private:
    float m_texHeight;      //����ĸ߶�
    float m_texWidth;       //����Ŀ��
    float m_renderWidth;    //����ʱ����������
    float m_renderHeight;   //����ʱ����������
    float m_tx;             //����ʱ��������������
    float m_ty;
    HTEXTURE m_hTex;
};

#endif