#include "pch.h"
#include "MonsterHPBar.h"
#include "BattleScene.h"
MonsterHPBar::MonsterHPBar(Scene* _Scene) :
	ConsoleObject(_Scene)
{
	SetImage(m_vecText, "HPBar.txt");
}

void MonsterHPBar::Update(float DeltaTime)
{

	ConsoleObject::Update(DeltaTime);
}

void MonsterHPBar::Render(float DeltaTime)
{
	ConsoleObject::Render(DeltaTime);
}

void MonsterHPBar::SetCursorPosY(const int& y)
{
	m_CursorPos.Y = (DWORD)y;
}
