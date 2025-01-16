#pragma once

static std::wstring toUnicode(const std::string& str)
{
	int len = MultiByteToWideChar(CP_ACP, NULL, str.c_str(), -1, NULL, NULL);
	WCHAR* buf = new WCHAR[sizeof(WCHAR) * len];
	MultiByteToWideChar(CP_ACP, NULL, str.c_str(), -1, buf, len);

	std::wstring result = buf;
	delete[] buf;
	return result;
}

static std::string toUTF8(const std::wstring& str)
{
	int len = WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), -1, NULL, NULL, NULL, NULL);
	char* buf = new char[sizeof(char)*len];
	WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), -1, buf, len, NULL, NULL);

	std::string result = buf;
	delete[] buf;
	return result;
}
