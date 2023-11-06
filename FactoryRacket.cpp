#include "FactoryRacket.h"
#include "BotRacket.h"
#include "PlayerRacket.h"

std::shared_ptr<IRenderable> FactoryRacket::Create(TypeRacketControl type, const sf::Vector2f& position, std::shared_ptr<Ball> ball)
{
    switch (type)
    {
    case TypeRacketControl::PLAYER:
    {
        return std::make_shared<PlayerRacket>(position, ball);
    }
    case TypeRacketControl::AI:
    {
        return std::make_shared<BotRacket>(position, ball);
    }
    }

    return nullptr;
}
