#pragma once
class StoreManager : public Singleton<StoreManager>
{
public:
	StoreManager();
	virtual ~StoreManager() override;
public:
	bool init();
	void run();
private:
	std::vector<class Shop*> m_vecStore;
private:
	EStoreMenu Menu();
};

