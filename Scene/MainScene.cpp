#include "pch.h"
#include "MainScene.h"
#include "ConsoleRender.h"
#include "KeyMgr.h"
#include "BattleManager.h"
#include "Player/Player.h"
#include "Monster.h" 
#include "Orc.h" 
#include "Goblin.h"
#include "Troll.h" 
#include "Slime.h"
#include "BossMonster.h"
#include "MonsterScene.h"
#include "FieldScene.h"
#include "Random.h"
#include "ShopScene.h"
#include "InventoryScene.h"
#include "MainViwer.h"
MainScene::~MainScene()
{
}

void MainScene::Start()
{
	m_vecObject.push_back(std::make_unique<MainViwer>(this));
}

void MainScene::Update(float DeltaTime)
{
	for (const auto& iter : m_vecObject)
		iter->Update(DeltaTime);
}


void MainScene::Render(float DeltaTime)
{
	for (const auto& iter : m_vecObject)
		iter->Render(DeltaTime);
}