#pragma once

#include "Singleton.h"

class ConsoleRender : public Singleton<ConsoleRender>
{
	friend class GameManager;
	friend class Scene;
public:
	ConsoleRender();
	virtual ~ConsoleRender();
private:
	struct stRect
	{
		unsigned int nWidth;
		unsigned int nHeight;
	};
	struct stConsole
	{
		HANDLE hConsole = nullptr;
		stRect rtConsole = {};
		HANDLE hBuffer[2] = {};
		HANDLE hInput = nullptr;
		int nBufferIdx = NULL;
	};
public:
	HANDLE getHandle()
	{
		return m_Console.hBuffer[m_Console.nBufferIdx];
	}
public:
	bool Init();
	void Update(float DeltaTime);
	void Render(float DeltaTime);
public:
	void SetTextColorAndBackGroundColor(WORD foregroundColor, WORD backgroundColor = NULL);
	void ScreenClear();
	void ScreenAllClear();
	void setCursorPosition(const short x, const short y);
public:
	void PrintText(HANDLE hOutput, const std::string& string);
	std::string InputText(const std::string& text = "");
private:
	stConsole                                          m_Console = {};
	CONSOLE_CURSOR_INFO                                m_cci = {};
	COORD                                              m_Pos = {};
	std::unique_ptr<class Scene>                       m_Scene;
public:
	void configureConsoleForRawInput(HANDLE hInput);
	class Scene* GetScene() const;
private:
	void ScreenInit();
	void ScreenFlipping();
	void ScreenRelease();
	void ScreenPrint(const std::string& str);
	void ScreenPrintln(const std::string& str);
public:
	void ChangeScene(std::unique_ptr<class Scene> Scene);
};

