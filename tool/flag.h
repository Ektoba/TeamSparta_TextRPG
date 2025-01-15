#pragma once
enum class EMainMenu : unsigned char
{
	None,
	Field,
	Store,
	Inventory,
	Exit
};
enum class EStoreMenu : unsigned char
{
	None,
	Weapon,
	Armor,
	Back
};
enum class EBattleMenu : char
{
	None = 0,
	Fight,
	UseItem,
	Run
};
enum class EItemType : unsigned char
{
	Weapon,
	Armor
};
enum class EStoreType : char
{
	None = -1,
	Weapon,
	Armor,
	Max
};

// MonsterType 정의
enum class MonsterType : int {  // unsigned char → int로 변경
	None = -1,
	Goblin,
	Orc,
	Troll,
	Dragon
};
enum class EBattleObjectType : unsigned char
{
	Menu,
	Message,
	MonsterArt,
	MonsterHPBar,
	Max
};