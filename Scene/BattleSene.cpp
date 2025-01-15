#include "pch.h"
#include "BattleScene.h"
#include "Logger.h"
#include "Monster.h"
#include "ConsoleRender.h"
#include "Player/Player.h"
#include "Monster.h"
#include "KeyMgr.h"
#include "MonsterArtObject.h"
#include "BattleMenuObject.h"
#include "BattleMessage.h"
#include "MonsterHPBar.h"
#include "../Manager/BattleManager.h"

BattleScene::BattleScene() :
	m_Monster(nullptr),
	m_Player(nullptr),
	m_Render(nullptr)
{
	if (m_Player == nullptr)
		m_Player = Player::GetInst();
}
BattleScene::BattleScene(Monster* Monster)
{
	m_Monster = Monster;
}

size_t BattleScene::GetCursorY(EBattleObjectType Obj)
{
	return m_vecObject[(int)Obj]->GetCursorY();
}

void BattleScene::Start()
{
	m_Player = Player::GetInst();
	m_Render = ConsoleRender::GetInst();
	m_vecObject.resize((int)EBattleObjectType::Max);
	m_vecObject[(int)EBattleObjectType::Menu] = std::make_unique<BattleMenuObject>(this);
	m_vecObject[(int)EBattleObjectType::Message] = std::make_unique<BattleMessage>(this);
	m_vecObject[(int)EBattleObjectType::MonsterArt] = std::make_unique<MonsterArtObject>(this);
	m_vecObject[(int)EBattleObjectType::MonsterArt]->SetImage(MonsterType::Dragon);
	m_vecObject[(int)EBattleObjectType::MonsterHPBar] = std::make_unique<MonsterHPBar>(this);
	m_vecObject[(int)EBattleObjectType::MonsterHPBar]->SetMonster(m_Monster);
	m_vecObject[(int)EBattleObjectType::MonsterHPBar]->SetCursorPos(CursorPos(0, (DWORD)m_vecObject[(int)EBattleObjectType::MonsterArt]->GetCursorY()));
}
void BattleScene::Update(float DeltaTime)
{
	size_t size = m_vecObject.size();
	CKeyMgr::GetInst()->update(m_Render->getHandle());
	m_Player->GetInst()->Update(DeltaTime);
	for (const auto& iter : m_vecObject)
	{
		iter.get()->Update(DeltaTime);
	}
}
void BattleScene::Render(float DeltaTime)
{
	size_t size = m_vecObject.size();
	m_Player->GetInst()->Render(DeltaTime);
	for (const auto& iter : m_vecObject)
	{
		iter.get()->Render(DeltaTime);
	}
}

void BattleScene::SetMonster(Monster* Monster)
{
	m_Monster = Monster;
}


void BattleScene::Fight()
{
	BattleMessage* Message = (BattleMessage*)m_vecObject[(int)EBattleObjectType::Message].get();
	
	std::string MonsterName = m_Monster->getName();
	std::string PlayerName = m_Player->getName();

	Message->m_vecText.push_back(PlayerName + "가 공격합니다.");
	std::string str = MonsterName + "가 " + std::to_string(Player::GetInst()->getAtk()) + "의 피해를 입습니다.";
	Message->m_vecText.push_back(str);
	m_Monster->takeDamage(Player::GetInst()->getAtk());

	//// TODO : 일정 시간 이후 메시지를 초기화하고 추가하는 기능이 있으면 좋겠다.
	Message->m_vecText.push_back(MonsterName + "가 공격합니다.");
	str = PlayerName + "가 " + std::to_string(m_Monster->getAttackPower()) + "의 피해를 입습니다.";
	Message->m_vecText.push_back(str);
	Player::GetInst()->takeDamage(m_Monster->getAttackPower());
	Message->m_Timer = true;

	if (m_Player->getCurrHealth() <= 0 || m_Monster->getHealth() <= 0)
	{
		BattleManager::GetInst()->BattleEnd();
	}
}

void BattleScene::useItem()
{
}

void BattleScene::runAway()
{
	BattleManager::GetInst()->BattleEnd();
}
