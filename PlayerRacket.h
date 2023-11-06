#pragma once
#include "BaseRacket.h"

class PlayerRacket : public BaseRacket
{
  public:
    PlayerRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed = 300.0f, float width = 10.0f, float height = 100.f);
    virtual void Update(float dt) override;
};
