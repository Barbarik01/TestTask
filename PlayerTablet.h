#pragma once
#include "BaseTablet.h"

class PlayerTablet : public BaseTablet
{
  public:
    PlayerTablet() = default;
    PlayerTablet(sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float Width = 10.0f,
                 float Height = 100.f);
    virtual void Update(float dt) override;
};
