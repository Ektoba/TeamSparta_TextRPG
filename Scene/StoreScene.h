#pragma once
#include "Scene.h"
class StoreScene :
    public Scene
{
    StoreScene();
    virtual ~StoreScene();
public:
    virtual void Start() override;
    virtual void Render(float DeltaTime) override;
    virtual void Update(float DeltaTime) override;
};

