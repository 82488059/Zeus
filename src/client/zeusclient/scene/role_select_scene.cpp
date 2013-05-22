#include "role_select_scene.h"
#include "play_scene.h"
#include "menu_scene.h"
#include "create_player_scene.h"
#include "control\pool\picture_pool.h"

#define SelectView_Role 1
#define Button_Return 2
#define Button_CreateRole 3
#define Button_DeleteRole 4
#define Button_StartGame 5

RoleSelectScene::RoleSelectScene()
{
    m_selectView = new SelectView(SelectView_Role, 10, 60, 780, 410);
    m_selectView->SetHorInterval(30);
    m_selectView->SetItemWidth(224);
    m_selectView->SetItemHeight(297);
    m_selectView->AddItem("RoleSelect-RoleBox", "RoleSelect-RoleBoxFocus");
    m_selectView->AddItem("RoleSelect-RoleBox", "RoleSelect-RoleBoxFocus");
    m_selectView->AddItem("RoleSelect-RoleBox", "RoleSelect-RoleBoxFocus");
    m_selectView->SetCurrentItem(0);

    m_returnBtn = new Button(Button_Return, 114, 38, "΢���ź�");
    m_returnBtn->SetBg("Btn_blue-Bg");
    m_returnBtn->SetBgMove("Btn_blue-Move");
    m_returnBtn->SetBgLButton("Btn_blue-LB");
    m_returnBtn->SetText("����");
    m_returnBtn->SetPos(36, 468);


    m_createRoleBtn = new Button(Button_CreateRole, 114, 38, "΢���ź�");
    m_createRoleBtn->SetBg("Btn_blue-Bg");
    m_createRoleBtn->SetBgMove("Btn_blue-Move");
    m_createRoleBtn->SetBgLButton("Btn_blue-LB");
    m_createRoleBtn->SetText("������ɫ");
    m_createRoleBtn->SetPos(159, 468);

    m_deleteRoleBtn = new Button(Button_DeleteRole, 114, 38, "΢���ź�");
    m_deleteRoleBtn->SetBg("Btn_blue-Bg");
    m_deleteRoleBtn->SetBgMove("Btn_blue-Move");
    m_deleteRoleBtn->SetBgLButton("Btn_blue-LB");
    m_deleteRoleBtn->SetText("ɾ����ɫ");
    m_deleteRoleBtn->SetPos(283, 468);
    
    m_startGameBtn = new Button(Button_StartGame, 114, 38, "΢���ź�");
    m_startGameBtn->SetBg("Btn_blue-Bg");
    m_startGameBtn->SetBgMove("Btn_blue-Move");
    m_startGameBtn->SetBgLButton("Btn_blue-LB");
    m_startGameBtn->SetText("��ʼ��Ϸ");
    m_startGameBtn->SetPos(606, 468);

    m_gui.AddCtrl(m_selectView);
    m_gui.AddCtrl(m_returnBtn);
    m_gui.AddCtrl(m_createRoleBtn);
    m_gui.AddCtrl(m_deleteRoleBtn);
    m_gui.AddCtrl(m_startGameBtn);
    m_gui.SetFocus(SelectView_Role);
    m_gui.Enter();
}

RoleSelectScene::~RoleSelectScene()
{

}

void RoleSelectScene::OnReturnBtnClick()
{
}
void RoleSelectScene::OnCreateRoleBtnClick()
{
    
}
void RoleSelectScene::OnDeleteRoleBtnClick()
{
    //�����ʱû��ʵ�� �Ȳ�д
}
void RoleSelectScene::OnStartGameBtnClick()
{

}

void RoleSelectScene::Update()
{
    //��ť�������˻᷵������id
    switch (m_gui.Update(hgeCreate(HGE_VERSION)->Timer_GetDelta()))
    {
    case Button_CreateRole:
        SceneEngine_->Pop();
        SceneEngine_->Push(new CreatePlayerScene);
        break;
    case Button_DeleteRole:
        break;
    case Button_Return:
        SceneEngine_->Pop();
        SceneEngine_->Push(new MenuScene);
        break;
    case Button_StartGame:
        SceneEngine_->Pop();
        SceneEngine_->Push(new PlayScene);
        break;
    default:
        break;
    }
}
void RoleSelectScene::Output()
{
    //��ɫ��ͼ
    GraphicsEngine::Instance()->Clear(ARGB(255,255,255,255));
    m_gui.Render();
}
void RoleSelectScene::Reset()
{
    GraphicsEngine::Instance()->Clear(ARGB(1,0,0,0));
}