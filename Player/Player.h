#pragma once

class Player : public Singleton<Player>
{
	friend class BattleManager;
public:
	Player();
	virtual ~Player() override;

public:
	bool init();

private:
	std::string              m_name;
	int32                    m_level;
	int32                    m_currHealth;
	int32                    m_maxHealth;
	int32                    m_atk;
	int32                    m_experience;
	int32                    m_gold;
	std::vector<class Item*> m_vecItem;
	class Scene*             m_Scene;
	std::unordered_map<std::string, std::shared_ptr<class ConsoleObject>> m_mapPlayerStatus;
public:
	const std::string& getName() const { return m_name; }
	const int32& getLevel()const { return m_level; }
	const int32& getCurrHealth() const { return m_currHealth; }
	const int32& getMaxHealth() const { return m_maxHealth; }
	const int32& getAtk() const { return m_atk; }
	const int32& getGold() const { return m_gold; }
	const int32& takeDamage(const int32 Damage);
	std::vector<class Item*> getVecItem() const { return m_vecItem; }
public:
	void SetName(const std::string& Name) { m_name = Name; }
	void SetGold(const int32& Gold) { m_gold = Gold; }
	void SetCurrentHealth(const int32& Health) { m_currHealth = Health; }
public:
	void addAtk(const int& Atk) { m_atk = Atk; }
	void addHealth(const int& Health) { m_currHealth = Health; }
public:
	void Update(float DeltaTime);
	void Render(float DeltaTime);

	void showPlayer();
	void levelUp();

	void addGold(int gold) { m_gold += gold; };

	void useItem(uint32 Idx);
	void addItem(Item* item) { m_vecItem.push_back(item); }
	void removeItem(uint32 index) { m_vecItem.erase(m_vecItem.begin() + index); }
};

