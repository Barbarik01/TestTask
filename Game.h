#pragma once
#include "Window.h"
#include "IRenderable.h"
#include <SFML/Audio.hpp>

class Game
{
  public:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void Run(float dt, Window& wnd);

  private:
    void Update(float dt);
    void Render(Window& wnd);

  private:
    std::vector<std::shared_ptr<IRenderable>> mObjects;
};
