#pragma once
class Store
{
protected:
	EStoreType m_Type;
	std::vector<class Item*> m_vecItem;
	uint32 m_ItemCount;
	uint32 m_ItemMaxCount;
public:
	void setStoreType(EStoreType Type) { m_Type = Type; }
	EStoreType getStoreType() const { return m_Type; }
	void addItem(class Item* item);
public:
	virtual bool init();
	virtual void run();
};

