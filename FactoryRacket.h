#pragma once
#include "Ball.h"
#include "IRenderable.h"

enum class TypeRacketControl
{
    PLAYER = 0,
    AI
};

class FactoryRacket
{
  public:
    static std::shared_ptr<IRenderable> Create(TypeRacketControl type, const sf::Vector2f& position, std::shared_ptr<Ball> ball);
};
