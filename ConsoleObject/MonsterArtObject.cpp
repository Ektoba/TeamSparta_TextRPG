#include "pch.h"
#include "MonsterArtObject.h"
#include "ConsoleRender.h"
#include "Logger.h"
#include "BattleScene.h"
#include "Monster.h"
MonsterArtObject::MonsterArtObject(class Scene* Scene) :
	ConsoleObject(Scene)
{
	m_Render = ConsoleRender::GetInst();
}

void MonsterArtObject::Update(float DeltaTime)
{
	ConsoleObject::Update(DeltaTime);
}

void MonsterArtObject::Render(float DeltaTime)
{
	ConsoleObject::Render(DeltaTime);
}

void MonsterArtObject::SetMonster(Monster* _Monster)
{
	m_Monster = _Monster;

	SetImage(m_Monster->getType());
}
