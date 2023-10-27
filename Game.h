#pragma once
#include "Ball.h"
#include "BaseTablet.h"
#include "HUD.h"
#include "Window.h"
#include <SFML/Audio.hpp>

class Game
{
  public:
    Game(Window& wnd);
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    void Run();

  private:
    void Update();
    void Render();

  private:
    Window& mWindow;
    sf::Clock clock;
    HUD mHud;
    std::vector<std::unique_ptr<BaseTablet>> mTablets;
    Ball ball;
    int mLeftScore;
    int mRightScore;
    sf::SoundBuffer mGoalSoundBuffer;
    sf::Sound mGoalSound;
};
