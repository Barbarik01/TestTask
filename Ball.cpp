#include "Ball.h"

Ball::Ball(const sf::Vector2f& position) 
    : mGen(mRd())
    , mDis(-1, 1)
{
    mBall.setRadius(mBallRadius);
    mBall.setPosition(position);
    mBall.setFillColor(sf::Color::White);

    SetRandomDirection();

    if(mBorderSoundBuffer.loadFromFile("Sounds\\BorderSound.mp3"))
        mBorderSound.setBuffer(mBorderSoundBuffer);

    if(mTabletSoundBuffer.loadFromFile("Sounds\\TabletSound.mp3"))
        mTabletSound.setBuffer(mTabletSoundBuffer);
}

void Ball::SetPosition(const sf::Vector2f& position)
{
    mBall.setPosition(position);
}

bool Ball::CheckCollisionWithTables(const BaseTablet& pBaseTablet) const
{
    return mBall.getGlobalBounds().intersects(pBaseTablet.GetGlobalBouds());
}

void Ball::CollisionWithTables()
{
    mDirection.x = -mDirection.x;

    if (mTabletSound.getBuffer())
        mTabletSound.play();
    
    mBallSpeed += 50;
}

void Ball::SetSpeed(float a) noexcept
{
    mBallSpeed = a;
}

float Ball::GetRadius() const noexcept
{
    return mBallRadius;
}

void Ball::Update(float dt)
{
    mBall.move(mDirection.x * mBallSpeed * dt, mDirection.y * mBallSpeed * dt);

    if (mBall.getPosition().y < 0 || mBall.getPosition().y + mBallRadius * 2 > Window::ScreenHeight)
    {
        mDirection.y = -mDirection.y;

        if (mBorderSound.getBuffer())
            mBorderSound.play();
    }
}

void Ball::Render(Window& window)
{
    window.Render(mBall);
}

const sf::Vector2f& Ball::GetPosition() const
{
    return mBall.getPosition();
}

void Ball::SetRandomDirection()
{
    do
    {
        mDirection.x = mDis(mGen);
    } while (mDirection.x > -0.6 && mDirection.x < 0.6);

    mDirection.y = mDis(mGen);
}

void Ball::SetNewPosition()
{
    mBall.setPosition(Window::ScreenWidth / 2, Window::ScreenHeight / 2);

    SetRandomDirection();
}
