//#include "scroll_bar.h"
//
//#define BTN_PROPORTION 0.037f    //��ť�뻬�������ȱ���
//
//ScrollBar::ScrollBar(int _id, float x, float y, float width, float height, int length, bool horizontal, int minMove, bool focusRemain)
//    : x(_x)
//    , y(_y)
//    , w(_width)
//    , h(_height)
//    , m_maxLen(length)
//    , m_hor(horizontal)
//    , m_minMove(minMove)
//    , m_focusRemain(focusRemain)
//    , m_pos(0)
//{
//    ///���ݱ������������ĳ���
//    m_sliderLen = minMove / length * height;
//
//    //���ݲ�ͬ�����������㰴ť�ľ���
//    if (horizontal)//���������
//    {
//        m_upBtnRect = new hgeRect(x - BTN_PROPORTION * width, y, x, y + height);
//        m_downBtnRect = new hgeRect(x + width, y, x + width + BTN_PROPORTION * width, y + height);
//    }
//    else  //���������
//    {
//        m_upBtnRect = new hgeRect(x, y - BTN_PROPORTION * height, x + width, y);
//        m_downBtnRect = new hgeRect(x , y + height, x + width, y + height + BTN_PROPORTION * height);
//    }
//
//    rect.Set(m_upBtnRect->x1, m_upBtnRect->y1, m_downBtnRect->x2, m_downBtnRect->y2);
//    
//}
//
//ScrollBar::~ScrollBar()
//{
//    delete m_upBtnRect;
//    delete m_downBtnRect;
//}
//
//void ScrollBar::Render()
//{
//    if (m_hor) //���������
//    {
//
//    }
//    else // ���������
//    {
//
//    }
//}
//
//
//
//void ScrollBar::Focus(bool bFocused)
//{
//    if (bFocused && !m_focusRemain) //��ͣ������ ���ݸ���һ��obj
//    {
//        gui->SetFocus(next->id);
//    }
//}
//
//void ScrollBar::MouseOver(bool bOver)
//{
//    float x = 0;
//    float y = 0;
//    hge->Input_GetMousePos(&x, &y);
//    if (bOver) // ������ 
//    {
//        //��ײ��up��ť
//        if (m_upBtnRect->TestPoint(x, y)) 
//        {
//
//        }
//        //��ײ��down��ť
//        else if (m_downBtnRect->TestPoint(x, y))
//        {
//
//        }
//        // ��ײ������������
//        else 
//        {
//
//        }
//    }
//    else // ����뿪
//    {
//    }
//}