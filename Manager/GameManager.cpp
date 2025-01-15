#include <pch.h>
#include "Logger.h"
#include "GameManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include "TimeManager.h"
#include "ConsoleRender.h"
#include "Player/Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "KeyMgr.h"
#include "MainScene.h"
GameManager::GameManager() : 
	m_GameEnd(false),
	m_BattleManager(nullptr),
	m_StoreManager(nullptr),
	m_Player(nullptr),
	m_ConsoleRender(nullptr)
{
	m_BattleManager = BattleManager::GetInst();
	//m_StoreManager = StoreManager::GetInst();
	m_Player = Player::GetInst();
	m_ConsoleRender = ConsoleRender::GetInst();
}

GameManager::~GameManager()
{
}

bool GameManager::init()
{
	if (m_Player->init() == false)
	{
		CLogger::GetInst()->Log(LOG_CATEGORY::Error, "플레이어 초기화 실패");
		return false;
	}
	if (m_ConsoleRender->Init() == false)
	{
		CLogger::GetInst()->Log(LOG_CATEGORY::Error, "Console 초기화 실패");
		return false;
	}
	if (m_BattleManager->init(m_ConsoleRender) == false)
	{
		CLogger::GetInst()->Log(LOG_CATEGORY::Error, "배틀 매니져 초기화 실패"); 
		return false;
	}
	if (!CKeyMgr::GetInst()->Init())
	{
		CLogger::GetInst()->Log(LOG_CATEGORY::Error, "키입력 매니져 초기화 실패");
		return false;
	}

	m_ConsoleRender->ChangeScene(std::make_unique<MainScene>());
	return true;
}

unsigned int GameManager::Run()
{
	while (!m_GameEnd)
	{
		Cicle();
	}
	return NULL;
}

void GameManager::GameEnd()
{
	m_GameEnd = true;
}

void GameManager::Cicle()
{
	float DeltaTime = CTimeManager::GetInst()->GetDeltaTime();
	Update(DeltaTime);
	Render(DeltaTime);
}

void GameManager::Update(float DeltaTime)
{
	ConsoleRender::GetInst()->Update(DeltaTime);
}

void GameManager::Render(float DeltaTime)
{
	ConsoleRender::GetInst()->Render(DeltaTime);
}
