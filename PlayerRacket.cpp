#include "PlayerRacket.h"
#include "MathUtils.h"

PlayerRacket::PlayerRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : BaseRacket(position, ball, speed, width, height)
{
}

void PlayerRacket::Update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && mRacket.getPosition().y > 0)
    {
        mRacket.move(0, -mRacketSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && mRacket.getPosition().y + mHeight < Window::ScreenHeight)
    {
        mRacket.move(0, mRacketSpeed * dt);
    }

    InteractWithBall();
}
