#include "BotTablet.h"

BotTablet::BotTablet(sf::Vector2f& position, const Ball& ball)
    : BaseTablet(position)
    , ball(ball)
{

}

void BotTablet::Update(float dt)
{
    if (ball.GetPosition().x < Window::ScreenWidth / 2)
        return;

    if (ball.GetPosition().y < mTablet.getPosition().y + tabletHeight / 2
        && mTablet.getPosition().y > 0)
    {
        mTablet.move(0, -tabletSpeed * dt);
    }

    if (ball.GetPosition().y + ball.ballRadius > mTablet.getPosition().y + tabletHeight / 2
        && mTablet.getPosition().y + tabletHeight < Window::ScreenHeight)
    {
        mTablet.move(0, tabletSpeed * dt);
    }
}
