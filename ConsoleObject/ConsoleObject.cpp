#include "pch.h"
#include "ConsoleObject.h"
#include "ConsoleRender.h"
#include "Logger.h"
ConsoleObject::ConsoleObject() :
	m_TextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY),
	m_BackGroundColor(NULL),
	m_Render(nullptr),
	m_hConsole(NULL),
	m_vecText{},
	m_SelectMenu(NULL)
{
	
}

ConsoleObject::ConsoleObject(Scene* Owner) :
	m_TextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY),
	m_BackGroundColor(NULL),
	m_Render(nullptr),
	m_hConsole(NULL),
	m_vecText{},
	m_SelectMenu(NULL)
{
	m_Owner = Owner;
}

ConsoleObject::ConsoleObject(ConsoleRender* Render)
{
	m_Render = Render;
}

ConsoleObject::~ConsoleObject()
{

}

void ConsoleObject::init()
{
	m_TextColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	m_TextColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
}

void ConsoleObject::Update(float DeltaTime)
{
	if (m_Render == nullptr)
		m_Render = ConsoleRender::GetInst();
}
void ConsoleObject::Render(float DeltaTime)
{
	if (m_vecText.empty())
		return;


	m_hConsole = m_Render->getHandle();
	size_t size = m_vecText.size();

	DWORD dw;
	
	m_Render->SetTextColorAndBackGroundColor(m_TextColor, m_BackGroundColor);
	for (size_t i = 0; i < size; ++i)
	{
		int strLen = MultiByteToWideChar(CP_ACP, 0, m_vecText[i].c_str(), -1, NULL, NULL);
		// UTF-16 버퍼 할당
		WCHAR wstr[512] = {};
		MultiByteToWideChar(CP_ACP, 0, m_vecText[i].c_str(), m_vecText[i].size(), wstr, strLen);
		//strLen = WideCharToMultiByte(CP_UTF8, NULL, wstr, -1, NULL, NULL,NULL,NULL);
		//WideCharToMultiByte(CP_UTF8, 0, wstr, -1, Utf, strLen,NULL,NULL);
		SetConsoleCursorPosition(m_hConsole, CursorPos(m_CursorPos.X, m_CursorPos.Y + (SHORT)i));
		// UTF-16 출력
		DWORD written;
		if (!WriteConsoleW(m_hConsole, wstr, strLen-1, &written, NULL)) {
			std::cerr << "Error: Failed to write to console.\n";
		}
	}
	m_Render->SetTextColorAndBackGroundColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void ConsoleObject::SetImage(MonsterType Type)
{
	std::filesystem::path Path = std::filesystem::current_path();
	Path /= "Art";
	switch (Type)
	{
	case MonsterType::None:
		break;
	case MonsterType::Goblin:
		Path /= "Goblin.txt";
		break;
	case MonsterType::Orc:
		Path /= "Orc.txt";
		break;
	case MonsterType::Troll:
		Path /= "Troll.txt";
		break;
	case MonsterType::Dragon:
		Path /= "Dragon.txt";
		break;
	default:
		break;
	}

	if (std::filesystem::is_regular_file(Path))
	{
		std::ifstream file(Path);
		std::string Line;
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				m_vecText.push_back(Line + "\n ");
			}
			file.close();
		}
		else
		{
			CLogger::GetInst()->Log(LOG_CATEGORY::Error, "not serch aski image");
		}
	}
}

void ConsoleObject::SetImage(std::vector<std::string>& vec, const std::string& file)
{
	auto Path = std::filesystem::current_path() / "Art";
	for (auto iter : std::filesystem::directory_iterator(Path))
	{
		std::string FileName = iter.path().filename().string();
		if (FileName == file)
		{
			std::ifstream file(iter.path());
			std::string Line = "";
			if (file.is_open())
			{
				while (getline(file, Line))
				{
					vec.push_back(Line + "\n ");
				}
				file.close();
			}
		}
	}
}

void ConsoleObject::SetMonster(Monster* _Monster)
{
	m_Monster = _Monster;
}
