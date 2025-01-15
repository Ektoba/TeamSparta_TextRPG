#include <pch.h>
#include "StoreManager.h"
#include "../Shop/Shop.h"
#include "../Shop/Store.h"
StoreManager::StoreManager()
{
}

StoreManager::~StoreManager()
{
	size_t size = m_vecStore.size();

	for (size_t i = 0; i < size; ++i)
	{
		delete m_vecStore[i];
	}

	m_vecStore.clear();
}

bool StoreManager::init()
{
    m_vecStore.resize((uint8)EStoreType::Max);
	// TODO : ????? ????
    return true;
}

void StoreManager::run()
{
    while (true)
    {
        EStoreMenu	StoreMenu = Menu();

        if (StoreMenu == EStoreMenu::Back)
            return;

        else if (StoreMenu == EStoreMenu::None)
            continue;

		m_vecStore[(uint8)StoreMenu - 1]->run();
    }
}

EStoreMenu StoreManager::Menu()
{
	system("cls");
	std::cout << "1. Weapon" << std::endl;
	std::cout << "2. Armor" << std::endl;
	std::cout << "3. Back" << std::endl;
	std::cout << "���ΰ��� ? : ";
	int	StoreMenu = 0;
	std::cin >> StoreMenu;

	if (StoreMenu <= (int)EStoreMenu::None ||
		StoreMenu > (int)EStoreMenu::Back)
		return EStoreMenu::None;

	return (EStoreMenu)StoreMenu;
}
