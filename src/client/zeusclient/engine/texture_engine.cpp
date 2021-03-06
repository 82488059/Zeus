#include "texture_engine.h"

template<> TextureEngine* Singleton<TextureEngine>::m_pInst = NULL;

TextureEngine::TextureEngine()
{
    m_GameEngine_Ptr = GameEngine::Instance();
}

TextureEngine::~TextureEngine()
{
}

GameTexture TextureEngine::Load(const std::string& path)
{
    if (!m_GameEngine_Ptr)
    {
        return 0;
    }
    return m_GameEngine_Ptr->Texture_Load(path);
}

int TextureEngine::GetWidth(GameTexture tex)
{
    if (!m_GameEngine_Ptr)
    {
        return 0;
    }
    return m_GameEngine_Ptr->Texture_GetWidth(tex);
}

int TextureEngine::GetHeight(GameTexture tex)
{
    if (!m_GameEngine_Ptr)
    {
        return 0;
    }
    return m_GameEngine_Ptr->Texture_GetHeight(tex);
}

void TextureEngine::Release(GameTexture tex)
{
    if (!m_GameEngine_Ptr)
    {
        return;
    }
    m_GameEngine_Ptr->Texture_Free(tex);
}

DWORD* TextureEngine::Lock(GameTexture tex,
                    bool bReadOnly,
                    int left,
                    int top,
                    int width,
                    int height)
{
    if (!m_GameEngine_Ptr)
    {
        return 0;
    }
    return m_GameEngine_Ptr->Texture_Lock(tex, bReadOnly,
        left, top, width, height);
}

void TextureEngine::Unlock(GameTexture tex)
{
    if (!m_GameEngine_Ptr)
    {
        return;
    }
    m_GameEngine_Ptr->Texture_UnLock(tex);
}

GameTexture TextureEngine::Create(float x, float y)
{
    if (!m_GameEngine_Ptr)
    {
        return 0;
    }
    return m_GameEngine_Ptr->PresentEngine()->Texture_Create((int)x, (int)y);
}