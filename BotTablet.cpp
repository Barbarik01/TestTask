#include "BotTablet.h"

BotTablet::BotTablet(sf::Vector2f& position, const Ball& ball) 
    : BaseTablet(position)
    , mBall(ball)
{
}

void BotTablet::Update(float dt)
{
    if (mBall.GetPosition().x < Window::ScreenWidth / 2)
        return;

    if (mBall.GetPosition().y < mTablet.getPosition().y + tabletHeight / 2 && mTablet.getPosition().y > 0)
    {
        mTablet.move(0, -mTabletSpeed * dt);
    }

    if (mBall.GetPosition().y + mBall.ballRadius > mTablet.getPosition().y + tabletHeight / 2 &&
        mTablet.getPosition().y + tabletHeight < Window::ScreenHeight)
    {
        mTablet.move(0, mTabletSpeed * dt);
    }
}
