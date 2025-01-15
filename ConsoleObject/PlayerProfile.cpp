#include "pch.h"
#include "PlayerProfile.h"

PlayerProfile::PlayerProfile()
{
	m_CursorPos = { 90, 0 };
	SetImage(m_vecText,"Profile.txt");
}

void PlayerProfile::Update(float DeltaTime)
{
	ConsoleObject::Update(DeltaTime);
}

void PlayerProfile::Render(float DeltaTime)
{
	ConsoleObject::Render(DeltaTime);
}
