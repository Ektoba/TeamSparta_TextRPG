 #include <pch.h>
#include "Manager/GameManager.h"
int main()
{
	int retVal = NULL;
	system("mode con cols=150 lines=60 | title Team-15 어떻게든 되겠죠");
	if (GameManager::GetInst()->init())
		retVal = GameManager::GetInst()->Run();

	return retVal;
}