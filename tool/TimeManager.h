#pragma once
#include "Singleton.h"
#include "Timer.h"

class CTimeManager : Singleton<CTimeManager>
{
	friend class GameManager;
	friend class BattleManager;
public:
	CTimeManager();
	~CTimeManager();
private:
	float m_DeltaTime;
	CTimer m_Timer;
private:
	bool Init();
	float GetDeltaTime();
};

