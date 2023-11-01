#include "PlayerTablet.h"

PlayerTablet::PlayerTablet(sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : BaseTablet(position, ball, speed, width, height)
{
}

void PlayerTablet::Update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && mTablet.getPosition().y > 0)
    {
        mTablet.move(0, -mTabletSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && mTablet.getPosition().y + mHeight < Window::ScreenHeight)
    {
        mTablet.move(0, mTabletSpeed * dt);
    }

    InteractWithBall();
}
