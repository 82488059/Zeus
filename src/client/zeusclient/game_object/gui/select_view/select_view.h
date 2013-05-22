#ifndef SELECT_VIEW_
#define SELECT_VIEW
//////////////////////////////////////////////////////////
//          SelectView GUI���
//
//  ����: �ṩ����Item �û�����ͨ���������߼������� ѡ����Ҫ��Item
//
//  Item������:  SelectView���������index��
//               ����tex���Ƿ�Ϊ����focus���ڿͻ�����Ӧ�ľ���rect
//  ע������: ���û������ width��height��Ϊ��һ��item��Tex��width��height
//////////////////////////////////////////////////////////
#include <list>
#include <string>
#include "game_object\gui\gui_item.h"
#include "control\control_object\texture_object.h"

struct SelectItem
{
    TextureObject* normalTex;       //ƽ������
    TextureObject* focusTex;        //Ϊ����ʱ������
    hgeRect rect;                  //�ڿͻ����ľ���
};
typedef std::list<SelectItem> SelectItemList;

class SelectView
    : public GUIItem
{
public:

    SelectView(int _id, float x, float y, float width, float height);
    ~SelectView();
    virtual void Render();
    virtual bool MouseLButton(bool bDown);
    virtual bool KeyClick(int key, int chr);

    void AddItem(const std::string normalTexID, const std::string focusTexID);
    void InserItem(int index, const std::string normalTexID, const std::string focusTexID);
    void DeleteItem(int index);
    void Clear();

    void SetItemTex(int index, const std::string normalTexID, const std::string focusTexID);
    //���û������ width��height��Ϊ��һ��item��Tex��width��height
    inline  void SetItemWidth(float w) { m_itemWidth = w; }
    inline  void SetItemHeight(float h) { m_itemHeight = h; }
    inline  void SetCurrentItem(int index);
    inline  void SetHorInterval(float interval) { m_intervalHor = interval; }
    inline  void SetVerInterval(float interval) { m_intervalVer = interval; }

    inline  int GetSelect() const { return m_currentIndex; }
    inline  int GetCount() const { return m_itemCount; }

    SelectItem GetItem(int index) const;

private:
    void Refresh();                         //�����䶯�� ���¼���Item����Ϣ

    SelectItemList m_items;               //��������item��Ϣ������
    float m_itemWidth;                      //ÿ��item�Ĵ�С�ɵ�һ��Ԫ�ؾ��� Ҳ�����趨
    float m_itemHeight;
    float m_intervalHor;                      //horizontal Item֮��ˮƽ���
    float m_intervalVer;                      //vertical Item֮�䴹ֱ���
    int m_currentIndex;                     //��ǰitem������
    int m_itemCount;                        //item������
    float m_x;
    float m_y;
    float m_height;
    float m_width;
};


#endif