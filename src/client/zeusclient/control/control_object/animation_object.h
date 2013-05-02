#ifndef ANIMATION_OBJECT_
#define ANIMATION_OBJECT_
#include "import\hge\include\hge.h"
#include "import\hge\include\hgeanim.h"
#include <string>

class AnimationObject
{
public:
    AnimationObject();
    virtual ~AnimationObject();
    bool Load(const std::string path
        ,  int frames                   //��֡��
        ,  float FPS                    //���������ٶ� ֡/��
        ,  float x                      //��һ֡����
        ,  float y
        ,  float w                      //ÿ֡��С
        ,  float h
        );

    void SetFrame(int index);
    int  GetCurrentFrame(); //ʧ�ܷ���-1
    void Play(int start, int end, bool loop);
    void Stop();
    void Update();
    void SetFPS(float FPS);
    void Render(float x, float y);

private:
    hgeAnimation* m_animation;
    HTEXTURE m_hTex;
    int m_start;            //��ʼ��֡
    int m_end;              //������֡
};


#endif