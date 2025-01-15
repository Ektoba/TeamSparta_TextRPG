#pragma once

#include "ConsoleObject.h"

class Scene
{
public:
    Scene();
    Scene(const Scene& Scene) = delete;
    virtual ~Scene() = NULL;
public:
    virtual void Start() = NULL;
    virtual void Update(float DeltaTime) = NULL;
    virtual void Render(float DeltaTime) = NULL;
protected:
    std::vector<std::unique_ptr<ConsoleObject>> m_vecObject;
};

