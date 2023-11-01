#pragma once
#include "Ball.h"
#include "BaseTablet.h"
#include "HUD.h"
#include "Window.h"
#include <SFML/Audio.hpp>

class Game : public BaseClass
{
  public:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void Run(float dt, Window& wnd);

  private:
    virtual void Update(float dt) override;
    virtual void Render(Window& wnd) override;

  private:
    std::vector<std::shared_ptr<BaseClass>> mObjects;
};
