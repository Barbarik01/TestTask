#include "BotRacket.h"
#include "MathUtils.h"

BotRacket::BotRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : BaseRacket(position, ball, speed, width, height)
{
    mAngle = -mAngle;
}

void BotRacket::Update(float dt)
{
    if (mBall->GetPosition().y < mRacket.getPosition().y + mHeight / 2 && mRacket.getPosition().y > 0)
    {
        mRacket.move(0, -mRacketSpeed * dt);
    }

    if (mBall->GetPosition().y + mBall->GetRadius() > mRacket.getPosition().y + mHeight / 2 &&
        mRacket.getPosition().y + mHeight < Window::ScreenHeight)
    {
        mRacket.move(0, mRacketSpeed * dt);
    }

    InteractWithBall();
}
