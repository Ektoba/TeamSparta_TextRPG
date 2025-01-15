#include "pch.h"
#include "Player.h"
#include "Manager/GameManager.h"
#include "PlayerStatusObject.h"
#include "PlayerProfile.h"
#include "ConsoleRender.h"
#include "Logger.h"
Player::Player() :
	m_name(),
	m_level(1),
	m_currHealth(0),
	m_maxHealth(200),
	m_atk(30),
	m_experience(0),
	m_gold(0),
	m_vecItem{}
{
	m_currHealth = m_maxHealth;
}

Player::~Player()
{
    GameManager::GetInst()->GameEnd();
    CLogger::GetInst()->Log(LOG_CATEGORY::Nomal,"플레이어가 죽었습니다 꾸엑.");
}

bool Player::init()
{
    m_mapPlayerStatus["Profile"] = std::make_shared<PlayerProfile>();
    m_mapPlayerStatus["Status"] = std::make_shared<PlayerStatusObject>();
    
    std::cout << ("                      ..:::.                      ") << std::endl;
    std::cout << ("                     #@@@@@@%.                    ") << std::endl;
    std::cout << ("                      *@@@@%                      ") << std::endl;
    std::cout << ("                       %%%%.                      ") << std::endl;
    std::cout << ("                       *@@#                       ") << std::endl;
    std::cout << ("                      .=##+.                      ") << std::endl;
    std::cout << ("                   .+%@@%%@@@*:                   ") << std::endl;
    std::cout << ("                  -@@@@*#%#@@@@+                  ") << std::endl;
    std::cout << ("                  @@%##@@@@%#%@@:                 ") << std::endl;
    std::cout << ("                 =##@@@@@@@@@@%%*                 ") << std::endl;
    std::cout << ("                 -@*-=+#@@%+=-*@+                 ") << std::endl;
    std::cout << ("                 -@@#=. @@. -*@@=                 ") << std::endl;
    std::cout << ("                 %@@@@+.@@:-@@@@@.                ") << std::endl;
    std::cout << ("                 =@@@@+ #%.-@@@@*                 ") << std::endl;
    std::cout << ("            =*#   #@@@+    -@@@#  =.:-            ") << std::endl;
    std::cout << ("       ::---@@==.  *@@+    -@@#  --  %  :-.       ") << std::endl;
    std::cout << ("    :=++*#@#@@@=.   -%+    -@-  .  -*: :-.  .:    ") << std::endl;
    std::cout << (" .*@@@@@@@@@@@*+#+:   :    .   .:--.     .:--=%+  ") << std::endl;
    std::cout << (" #+-...:-=+*###=  .:.         .    .:--==-:...:=* ") << std::endl;
    
    std::cout << ("====================스파르타마을====================") << std::endl;
    std::cout << ("스파르타 마을에 오신 것을 환영합니다.") << std::endl;
    std::cout << ("던전으로 들어가기전 활동을 할 수 있습니다.") << std::endl;
    std::cout << ("===================================================") << std::endl;
    std::cout << ("용사님의 존함을 알려주십시오 : ");
    std::cin >> m_name;
	return true;
}

void Player::levelUp()
{
	++m_level;
	m_maxHealth = m_level * 20;
	m_currHealth = m_maxHealth;
	m_atk = m_atk +  m_level * 5;
}

void Player::useItem(uint32 Idx)
{
}

const int32& Player::takeDamage(const int32 Damage)
{
    if (m_currHealth - Damage <= 0)
        Destroy();

    m_currHealth -= Damage;
    return m_currHealth;
}

void Player::Update(float DeltaTime)
{
    if (m_Scene == nullptr)
    {
        m_Scene = ConsoleRender::GetInst()->GetScene();
    }
    for (const auto& iter : m_mapPlayerStatus)
    {
        iter.second->Update(DeltaTime);
    }
}

void Player::Render(float DeltaTime)
{
    for (const auto& iter : m_mapPlayerStatus)
    {
        iter.second->Render(DeltaTime);
    }
}

void Player::showPlayer()
{
}
