#pragma once
#include "ConsoleObject.h"
class MonsterArtObject :
    public ConsoleObject
{
public:
    MonsterArtObject(class Scene* Scene);
public:
    virtual void Update(float DeltaTime) override;
    virtual void Render(float DeltaTime) override;
    virtual void SetMonster(class Monster* _Monster) override;
private:
    MonsterType m_MonsterType;
};

