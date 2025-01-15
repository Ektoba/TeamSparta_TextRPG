#pragma once
#include "Singleton.h"
#include <fstream>
enum class LOG_CATEGORY
{
	Nomal,
	Warning,
	Error,
	MAX
};
class CLogger : public Singleton<CLogger>
{
public:
	CLogger();
	CLogger(const CLogger&) = delete;
	CLogger& operator=(const CLogger&) = delete;
	virtual ~CLogger() override;
private:
	std::ofstream m_LogFile;
public:
	void Log(LOG_CATEGORY Category,const std::string& message);
};

