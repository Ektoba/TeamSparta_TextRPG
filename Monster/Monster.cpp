#include "pch.h"
#include "Player.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

Monster::Monster(const std::string& name, int playerLevel, MonsterType monsterType)
    : name(name), health(0), attackPower(0)
{
    updateStats(playerLevel);
}

void Monster::updateStats(int playerLevel)
{
    health = getRandomValue(playerLevel * 20, playerLevel * 30);
    attackPower = getRandomValue(playerLevel * 5, playerLevel * 10);
}

void Monster::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
        health = 0;
}

int Monster::getRandomValue(int min, int max) const
{
    static bool seedSet = false;
    if (!seedSet)
    {
        srand(static_cast<unsigned>(time(0)));
        seedSet = true;
    }
    return min + (rand() % (max - min + 1));
}

void Monster::attack(Player& player)
{
    // 怨듦꺽?λ쭔???뚮젅?댁뼱??泥대젰??媛먯냼?쒗궡
    std::cout << name << " attacks " << player.getName() << " for " << attackPower << " damage!" << std::endl;
    player.takeDamage(attackPower);
}

std::pair<int, int> Monster::dropItem() const
{
    int gold = getRandomValue(10, 30);

    int experience = getRandomValue(20, 60);


    return { gold,experience };
}