#pragma once
#include "../Player/Player.h"

class Item
{
public:
	enum class ItemType
	{
		HealthPotion,
		AttackBoost
	};

private:
	ItemType	m_itemType;
	std::string m_itemName;
	uint32		m_itemPrice;

public:
	Item(ItemType type, const std::string& name, uint32 price) 
		: m_itemType(type), m_itemName(name), m_itemPrice(price) {}

	virtual ~Item() = default;

public:
	std::string getName() const { return m_itemName; }
	uint32 getPrice() const { return m_itemPrice; }
	virtual void use(Player* player) = 0;
};

