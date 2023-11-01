#include "BaseTablet.h"

BaseTablet::BaseTablet(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height)
    : mBall(ball)
    , mTabletSpeed(speed)
    , mWidth(width)
    , mHeight(height)
{
    SetPositon(position);
    SetSize(sf::Vector2f(width, height));
    mTablet.setFillColor(sf::Color::White);
}

sf::FloatRect BaseTablet::GetGlobalBouds() const
{
    return mTablet.getGlobalBounds();
}

bool BaseTablet::InteractWithBall()
{
    if (mBall->CheckCollisionWithTables(*this))
    {
        mBall->CollisionWithTables();

        return true;
    }

    return false;
}

float BaseTablet::GetWidth() const noexcept
{
    return mWidth;
}

float BaseTablet::GetHeight() const noexcept
{
    return mHeight;
}

void BaseTablet::SetSize(const sf::Vector2f& size)
{
    mTablet.setSize(size);
}

void BaseTablet::SetPositon(const sf::Vector2f& position)
{
    mTablet.setPosition(position);
}

void BaseTablet::Update(float dt)
{
}

void BaseTablet::Render(Window& window)
{
    window.Render(mTablet);
}
