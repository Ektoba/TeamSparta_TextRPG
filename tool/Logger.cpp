#include "Logger.h"
#include <mutex>
CLogger::CLogger()
{
	m_LogFile.open("log.txt", std::ios::app); // 로그 파일 열기 (append 모드)
	if (!m_LogFile.is_open()) throw std::runtime_error("Unable to open log file.");
}

CLogger::~CLogger()
{
	if (m_LogFile.is_open()) m_LogFile.close();
}


void CLogger::Log(LOG_CATEGORY Category,const std::string& message)
{
	std::string category;
	switch (Category)
	{
	case LOG_CATEGORY::Nomal:
		category = "[Log]";
		break;
	case LOG_CATEGORY::Warning:
		category = "[Warning]";
		break;
	case LOG_CATEGORY::Error:
		category = "[Error]";
		break;
	case LOG_CATEGORY::MAX:
		break;
	default:
		break;
	}
	if (m_LogFile.is_open())
	{
		static std::mutex logMutex;
		std::lock_guard<std::mutex> lock(logMutex);
		m_LogFile << category << message << std::endl;
	}
}
