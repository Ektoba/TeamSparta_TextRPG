#pragma once
#define _CRTDBG_MAP_ALLOC
#define LOGGER(X) CLogger::GetInst()->Log(LOG_CATEGORY::Error, X)
//#define GetKey(X) CKeyMgr::GetInst()->GetKeyState(X) == KEY_STATE::TAP

using int8 = __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

#define ConsoleWidth 150
#define ConsoleHeight 70

#define IS_TAB(KEY) CKeyMgr::GetInst()->GetKeyState(KEY) == KEY_STATE::TAP
#define IS_AWAY(KEY) CKeyMgr::GetInst()->GetKeyState(KEY) == KEY_STATE::AWAY
#define IS_PRESSED(KEY) CKeyMgr::GetInst()->GetKeyState(KEY) == KEY_STATE::PRESSED