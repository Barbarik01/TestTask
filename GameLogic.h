#pragma once
#include "Ball.h"
#include "HUD.h"
#include "IRenderable.h"

class GameLogic : public IRenderable
{
  public:
    GameLogic() = delete;
    explicit GameLogic(std::shared_ptr<Ball> ball, std::shared_ptr<HUD> hud);
    virtual void Update(float dt) override;
    virtual void Render(Window& wnd) override;

  private:
    void UpdateAfterGoal();
    void PlaySound();

  private:
    std::shared_ptr<Ball> pBall = nullptr;
    std::shared_ptr<HUD> pHud = nullptr;
    std::pair<int, int> mScore = {0, 0};
    sf::SoundBuffer mGoalSoundBuffer;
    sf::Sound mGoalSound;
};
