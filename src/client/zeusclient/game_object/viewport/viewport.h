#ifndef VIEWPORT_
#define VIEWPORT_
#include "include\utils\Singleton.h"
#include "import\hge\include\hgevector.h"

typedef hgeVector viewportVector;

class Viewport
    : public Singleton<Viewport>
{
public:
    Viewport();
    ~Viewport();

    //ȡ�ӿ���������
    viewportVector GetPos();
    void SetPos(float x, float y);

private:
    viewportVector m_pos;
};
#endif