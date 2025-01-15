﻿#pragma once
#include "BattleScene.h"

class BattleManager : public Singleton<BattleManager>
{
public:
	BattleManager();
	BattleManager(class ConsoleRender* Render);
	virtual ~BattleManager() override;
public:
	bool init();
	bool init(class ConsoleRender* Render);
	void run();
	void BattleEnd() { m_battleEnd = true; }
private:
	void Update(float DeltaTime);
	void Render(float DeltaTime);
private:
	BattleScene m_Battle;
private:
	class Player* m_Player;
	std::unique_ptr<class Monster> m_Monster;
	class ConsoleRender* m_Render;
	class BattleScene* m_RenderObj;
	bool m_battleEnd = false;
public:
	void battle(Monster* Monster);
	void battle(std::unique_ptr<class Monster> Monster);
};

