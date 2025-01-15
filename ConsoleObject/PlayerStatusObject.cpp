#include "pch.h"
#include "PlayerStatusObject.h"
#include "ConsoleObject.h"
#include "../Player/Player.h"
#include "ConsoleRender.h"
PlayerStatusObject::PlayerStatusObject()
{
	m_CursorPos = {115, 5};
}

void PlayerStatusObject::Update(float DeltaTime)
{
	m_vecText.clear();
	m_vecText.push_back("�̸�   : " + Player::GetInst()->getName());
	m_vecText.push_back("����   : " + std::to_string(Player::GetInst()->getLevel()));
	m_vecText.push_back("ü��   : " + std::to_string(Player::GetInst()->getCurrHealth()) + "/" + std::to_string(Player::GetInst()->getMaxHealth()));
	m_vecText.push_back("������ : " + std::to_string(Player::GetInst()->getGold()));
	ConsoleObject::Update(DeltaTime);
}

void PlayerStatusObject::Render(float DeltaTime)
{
	ConsoleObject::Render(DeltaTime);
}
