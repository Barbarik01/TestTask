#pragma once
#include "Window.h"

class IRenderable
{
  public:
    virtual void Update(float dt) = 0;
    virtual void Render(Window& wnd) = 0;
    virtual ~IRenderable() = default;
};
