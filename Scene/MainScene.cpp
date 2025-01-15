#include "pch.h"
#include "MainScene.h"
#include "ConsoleRender.h"
#include "KeyMgr.h"
#include "../Manager/BattleManager.h"
#include "Orc.h"
#include "Player/Player.h"
MainScene::~MainScene()
{
}

void MainScene::Start()
{
	m_vecText.push_back("1. 사냥터");
	m_vecText.push_back("2. 상점");
	m_vecText.push_back("3. 인벤토리");
	m_vecText.push_back("4. 게임종료");
	m_SelectMenu = 1;
}

void MainScene::Update(float DeltaTime)
{
	if (IS_TAB(KEY::W))
	{
		m_SelectMenu = m_SelectMenu > 1 ? m_SelectMenu - 1 : 1;
	}
	else if (IS_TAB(KEY::S))
	{
		int size = (int)m_vecText.size();
		m_SelectMenu = m_SelectMenu < size ? m_SelectMenu + 1 : size;
	}
	else if (IS_TAB(KEY::SPACE))
	{
		switch ((EMainMenu)m_SelectMenu)
		{
		case EMainMenu::None:
			break;
		case EMainMenu::Field:
		{
			BattleManager::GetInst()->battle(std::make_unique<Orc>(Player::GetInst()->getLevel()));
		}
			break;
		case EMainMenu::Store:
			break;
		case EMainMenu::Inventory:
			break;
		case EMainMenu::Exit:
			break;
		default:
			break;
		}
	}
}

void MainScene::Render(float DeltaTime)
{
	HANDLE handle = ConsoleRender::GetInst()->getHandle();
	CKeyMgr::GetInst()->update(handle);
	DWORD dw;
	CursorPos Pos(3,0);

	size_t size = NULL;

	for (const auto& iter : m_vecText)
	{
		SetConsoleCursorPosition(handle, Pos);
		WriteFile(handle, iter.c_str(), (DWORD)iter.size(), &dw, nullptr);
		Pos.Y++;
	}
	Pos.Y = 0;
	Pos.X = 0;

	Pos.Y += (DWORD)m_SelectMenu-1;
	SetConsoleCursorPosition(handle, Pos);
	WriteFile(handle, ">", (DWORD)1, &dw, nullptr);
}
