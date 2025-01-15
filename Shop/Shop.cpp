#include "pch.h"
#include "Shop.h"
#include "../Item/AttackBoost.h"
#include "../Item/HealthPotion.h"
#include <memory>


Shop::Shop()
{
	items.emplace_back(std::make_unique<AttackBoost>);
	items.emplace_back(std::make_unique<HealthPotion>);
}

void Shop::displayItems() const
{
	std::cout << "====================" << std::endl;
	std::cout << "─███─█──█─████─████─" << std::endl;
	std::cout << "─█───█──█─█──█─█──█─" << std::endl;
	std::cout << "─███─████─█──█─████─" << std::endl;
	std::cout << "───█─█──█─█──█─█────" << std::endl;
	std::cout << "─███─█──█─████─█────" << std::endl;
	std::cout << "====================" << std::endl;
	
	// 상점 아이템 목록 출력
	for (int i = 0; i < items.size(); i++)
	{
		std::cout << i + 1 << ". " << items[i]->getName() << std::endl;
	}
}

void Shop::buyItem(int index, Player* player)
{
	// player 유효성 검사
	if (player == nullptr)
	{
		return;
	}

	// index 유효성 검사
	if (index <= 0 || index >= items.size())
	{
		std::cerr << "구매할 아이템이 존재하지 않습니다." << std::endl;
		return;
	}

	// 구매한 아이템
	std::unique_ptr<Item> BuyItem = std::move(items[index - 1]);
	uint32 BuyPrice = BuyItem->getPrice();
	
	// player의 소지 골드 검사
	if (player->getGold() >= BuyPrice)
	{
		// player 아이템 목록에 구매한 아이템 추가
		player->addItem(std::move(BuyItem));

		// 상점 아이템 목록에서 구매한 아이템 제거
		items.erase(items.begin() + index - 1);

		std::cout << BuyItem->getName() << " 구매 완료!" << std::endl;

		// player 골드 감소
		player->addGold(-BuyPrice);
	}
	else 
	{
		std::cout << "골드가 부족합니다." << std::endl;
		return;
	}
}

void Shop::sellItem(int index, Player* player)
{
	// player 유효성 검사
	if (player == nullptr)
	{
		return;
	}

	// index 유효성 검사
	if (index <= 0 || index >= player->getVecItem().size())
	{
		std::cerr << "판매할 아이템이 존재하지 않습니다." << std::endl;
		return;
	}

	// 판매할 아이템
	std::unique_ptr<Item> SellItem = std::move(player->getVecItem()[index - 1]);
	uint32 SellPrice = SellItem->getPrice() * 0.6;
	
	
	// 판매 여부 확인
	std::cout << SellItem->getName() << "을(를) 판매합니다. [y/n]" << std::endl;
	char answer;
	std::cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		// player 아이템 목록에서 판매한 아이템 제거
		player->removeItem(index - 1);

		std::cout << "판매 완료!" << std::endl;

		// player 골드 증가
		player->addGold(SellPrice);
	}
	else
	{
		std::cout << "판매를 취소했습니다." << std::endl;
		return;
	}
}
