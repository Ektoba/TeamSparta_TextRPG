#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	uint32		m_attackIncrease;

public:
	AttackBoost() : Item(ItemType::AttackBoost, "ÈûÀÇ ¿µ¾à", 15), m_attackIncrease(10) {}

public:
	void use(Player* player) override { player->addAtk(m_attackIncrease); }
};

