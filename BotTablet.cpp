#include "BotTablet.h"

BotTablet::BotTablet(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : BaseTablet(position, ball, speed, width, height)
{
}

void BotTablet::Update(float dt)
{
    if (mBall->GetPosition().x < Window::ScreenWidth / 2)
        return;

    if (mBall->GetPosition().y < mTablet.getPosition().y + mHeight / 2 && mTablet.getPosition().y > 0)
    {
        mTablet.move(0, -mTabletSpeed * dt);
    }

    if (mBall->GetPosition().y + mBall->GetRadius() > mTablet.getPosition().y + mHeight / 2 &&
        mTablet.getPosition().y + mHeight < Window::ScreenHeight)
    {
        mTablet.move(0, mTabletSpeed * dt);
    }

    InteractWithBall();
}
