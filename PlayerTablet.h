#pragma once
#include "BaseTablet.h"

class PlayerTablet : public BaseTablet
{
  public:
    PlayerTablet() = default;
    PlayerTablet(sf::Vector2f& position);
    virtual void Update(float dt) override;
};
