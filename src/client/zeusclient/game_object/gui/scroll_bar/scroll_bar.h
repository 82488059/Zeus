#ifndef SCROLL_BAR_
#define SCROLL_BAR_
#include "game_object\gui\gui_item.h"
#include "game_object\gui\button\button.h"
#include "import\hge\include\hge.h"
#include "import\hge\include\hgecolor.h"
class ScrollBar
    : public GUIItem
{
public:
    ScrollBar(int _id, float _x, float _y, float width, float height, int length, bool horizontal = false, int minMove = 1, bool focusRemain = false);
    ~ScrollBar();

    virtual void Render();
    //virtual void Reset();
    virtual void Focus(bool bFocused);
    virtual void MouseOver(bool bOver);
    void SetSliderColor(DWORD color);

    float x;                  //����up down��ť���λ��
    float y;
    float h;                  //����up down��ť��Ĵ�С
    float w;

private:

    float m_pos;                //��ǰ����λ�� �ðٷֱȱ�ʾ
    float m_sliderLen;          //������ʾ�ĳ���
    int m_minMove;              //��������С�ƶ����߼�����
    int m_maxLen;               //��������ʾ���߼�����
    hgeRect* m_upBtnRect;       //���ϵİ�ť
    hgeRect* m_downBtnRect;     //���µİ�ť
    bool m_hor;                 //�Ƿ�Ϊˮƽ������
    bool m_focusRemain;         //�Ƿ�����ͣ������
    hgeColor m_upBtnColor;
    hgeColor m_downBtnColor;
};



#endif