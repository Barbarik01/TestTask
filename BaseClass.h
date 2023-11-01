#pragma once
#include "Window.h"

class BaseClass
{
  public:
    virtual void Update(float dt) = 0;
    virtual void Render(Window& window) = 0;
    virtual ~BaseClass() = default;
};
