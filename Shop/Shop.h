#pragma once
#include "../Manager/GameManager.h"
#include "../Player/Player.h"
#include "../Item/Item.h"

class Shop
{
private:
	std::vector<std::unique_ptr<Item>> items;

public:
	Shop();
	~Shop() = default;

public:
	void displayItems() const;
	void buyItem(int index, Player* player);
	void sellItem(int index, Player* player);
};

