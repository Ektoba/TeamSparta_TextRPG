#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
	uint32 m_healthRestore;

public:
	HealthPotion() : Item(ItemType::HealthPotion, "ü�� ����", 10), m_healthRestore(50) {}

public:
	void use(Player* player) override { player->addHealth(m_healthRestore); };
};

