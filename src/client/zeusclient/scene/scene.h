#ifndef SCENE
#define SCENE


class Scene
{
public:
    Scene() {}
    ///> todo: �������������඼Ҫ������������������deleteָ������ĸ���ָ��ʱ���ڴ�й©
    ~Scene() {}

    virtual void Update() = 0;
    virtual void Output() = 0;
    virtual void Reset()  = 0;

private:

};

#endif