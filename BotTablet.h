#pragma once
#include "Ball.h"
#include "BaseTablet.h"

class BotTablet : public BaseTablet
{
  public:
    BotTablet() = default;
    BotTablet(sf::Vector2f& position, const Ball& ball);
    virtual void Update(float dt) override;

  private:
    const float mTabletSpeed = 200.0f;
    const Ball& mBall;
};
