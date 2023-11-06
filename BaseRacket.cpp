#include "BaseRacket.h"
#include "MathUtils.h"

BaseRacket::BaseRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : mBall(ball)
    , mRacketSpeed(speed)
    , mWidth(width)
    , mHeight(height)
{
    SetPositon(position);
    SetSize(sf::Vector2f(width, height));
    mRacket.setFillColor(sf::Color::White);
}

void BaseRacket::SetSize(const sf::Vector2f& size)
{
    mRacket.setSize(size);
}

void BaseRacket::SetPositon(const sf::Vector2f& position)
{
    mRacket.setPosition(position);
}

void BaseRacket::InteractWithBall()
{
    sf::Vector2f direction = mBall->GetDirection();

    switch (IsRightSideInteract())
    {
    case SideInteract::TOP_BOTTOM:
    {
        direction.y = -direction.y;
        mBall->SetDirection(direction);

        break;
    }
    case SideInteract::RIGHT_LEFT:
    {
        if (mBall->GetPosition().y < mRacket.getPosition().y + mHeight / 2)
        {
            MathUtils::RotateVectorOnAgle(direction, mAngle, true);
        }
        else
        {
            MathUtils::RotateVectorOnAgle(direction, mAngle, false);
        }

        MathUtils::NormalizeVector(direction);
        mBall->SetDirection(direction);

        mBall->CollisionWithTables();
    }
    case SideInteract::NONE:
    {
        break;
    }
    }
}

SideInteract BaseRacket::IsRightSideInteract()
{
    sf::Vector2f ballCenter(mBall->GetPosition().x + mBall->GetRadius(), mBall->GetPosition().y + mBall->GetRadius());
    sf::Vector2f rectCenter(mRacket.getPosition().x + mRacket.getSize().x / 2,
                            mRacket.getPosition().y + mRacket.getSize().y / 2);

    float dx = abs(ballCenter.x - rectCenter.x);
    float dy = abs(ballCenter.y - rectCenter.y);

    float minDistX = (mBall->GetRadius() + mRacket.getSize().x / 2);
    float minDistY = (mBall->GetRadius() + mRacket.getSize().y / 2);

    if (dx <= minDistX && dy <= minDistY)
    {
        float overlapX = minDistX - dx;
        float overlapY = minDistY - dy;

        if (overlapX > overlapY)
        {
            return SideInteract::TOP_BOTTOM;
        }
        else
        {
            return SideInteract::RIGHT_LEFT;
        }
    }

    return SideInteract::NONE;
}

void BaseRacket::Render(Window& wnd)
{
    wnd.GetWindow()->draw(mRacket);
}
