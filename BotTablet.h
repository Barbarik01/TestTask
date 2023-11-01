#pragma once
#include "Ball.h"
#include "BaseTablet.h"

class BotTablet : public BaseTablet
{
  public:
    BotTablet() = default;
    BotTablet(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width = 10.0f,
              float height = 100.f);
    virtual void Update(float dt) override;
};
