#pragma once
#include "ConsoleObject.h"
class MainViwer :
    public ConsoleObject
{
public:
    MainViwer(class Scene* Scene);
    virtual void Update(float DeltaTime);
    virtual void Render(float DeltaTime);
private:
    std::vector<std::string> m_vecSelectText;
};

