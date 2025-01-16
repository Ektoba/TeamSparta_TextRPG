#include "pch.h"
#include "MainViwer.h"
#include "ConsoleRender.h"
#include "KeyMgr.h"
#include "Player.h"
#include "FieldScene.h"
#include "ShopScene.h"
#include "InventoryScene.h"

MainViwer::MainViwer(Scene* Scene) : 
	ConsoleObject(Scene)
{

	m_CursorPos = { 0, };
	SetImage(m_vecText, "House");
    m_vecSelectText.push_back("1. 모험");
    m_vecSelectText.push_back("2. 상점");
    m_vecSelectText.push_back("3. 인벤토리");
    m_vecSelectText.push_back("4. 게임종료");
    m_SelectMenu = 1;
}

void MainViwer::Update(float DeltaTime) 
{
	ConsoleObject::Update(DeltaTime);
    if (IS_TAB(KEY::W))
    {
        m_SelectMenu = m_SelectMenu > 1 ? m_SelectMenu - 1 : 1;
    }
    else if (IS_TAB(KEY::S))
    {
        uint32 size = (uint32)m_vecSelectText.size();
        m_SelectMenu = m_SelectMenu < size ? m_SelectMenu +1 : size;
    }
    else if (IS_TAB(KEY::SPACE))
    {
        switch ((EMainMenu)m_SelectMenu)
        {
        case EMainMenu::None:
            break;

        case EMainMenu::Field:
        {
            CursorPos pos = Player::GetInst()->getFieldPos();
            ConsoleRender::GetInst()->CreateScene<FieldScene>();
        }
        break;

        case EMainMenu::Store:
            ConsoleRender::GetInst()->CreateScene<ShopScene>();
            break;

        case EMainMenu::Inventory:
            // 인벤토리 추가
            ConsoleRender::GetInst()->CreateScene<InventoryScene>();
            break;

        case EMainMenu::Exit:
            std::cout << "게임을 종료합니다!" << std::endl;
            exit(0);
            break;

        default:
            break;
        }
    }
}

void MainViwer::Render(float DeltaTime)
{
	ConsoleObject::Render(DeltaTime);

    size_t count = NULL;
    DWORD dw;
    short height = m_CursorPos.Y + m_vecText.size();
    for (const auto& iter : m_vecSelectText)
    {
        SetConsoleCursorPosition(m_hConsole, CursorPos(m_CursorPos.X, height+ count));
        std::wstring str = toUnicode(iter.c_str());
        WriteConsoleW(m_hConsole, str.c_str(), (DWORD)str.size(), &dw, nullptr);
        count++;
    }
    
    SetConsoleCursorPosition(m_hConsole, CursorPos(m_CursorPos.X, height + m_SelectMenu-1));
    WriteConsoleW(m_hConsole, L">", (DWORD)1, &dw, nullptr);

}
