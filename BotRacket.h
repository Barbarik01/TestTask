#pragma once
#include "Ball.h"
#include "BaseRacket.h"

class BotRacket : public BaseRacket
{
  public:
    BotRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed = 250.0f, float width = 10.0f, float height = 100.f);
    virtual void Update(float dt) override;
};
