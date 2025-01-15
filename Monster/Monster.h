#pragma once
#include <string>

#include "pch.h"

class Player;

class Monster
{
protected:
    std::string name;
    int health;
    int attackPower;
    MonsterType type; // 몬스터 타입

public:
    Monster(const std::string& name, int playerLevel, MonsterType monsterType);
    virtual ~Monster() = default;
    virtual void updateStats(int playerLevel);
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    MonsterType getType() const { return type; } // 타입 반환
    void takeDamage(int damage);
    void attack(Player& player); // 플레이어를 공격하는 메서드

    std::pair<int, int> dropItem() const; // 처치 시 돈과 경험치 반환

private:
    int getRandomValue(int min, int max) const;
};
