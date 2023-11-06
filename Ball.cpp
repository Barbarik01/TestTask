#include "Ball.h"
#include "MathUtils.h"

Ball::Ball(const sf::Vector2f& position) 
    : mGen(mRd())
    , mDis(-1, 1)
{
    mBall.setRadius(mBallRadius);
    mBall.setPosition(position);
    mBall.setFillColor(sf::Color::White);

    SetRandomDirection();

    if (mBorderSoundBuffer.loadFromFile("Sounds\\BorderSound.mp3"))
        mBorderSound.setBuffer(mBorderSoundBuffer);

    if (mTabletSoundBuffer.loadFromFile("Sounds\\TabletSound.mp3"))
        mTabletSound.setBuffer(mTabletSoundBuffer);
}

void Ball::SetPosition(const sf::Vector2f& position)
{
    mBall.setPosition(position);
}

void Ball::CollisionWithTables()
{
    mDirection.x = -mDirection.x;

    MathUtils::NormalizeVector(mDirection);

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

void Ball::SetDirection(const sf::Vector2f& direction)
{
    mDirection = direction;
}

const sf::Vector2f& Ball::GetDirection() const
{
    return mDirection;
}

const sf::CircleShape& Ball::GetBall() const
{
    return mBall;
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

void Ball::Render(Window& wnd)
{
    wnd.GetWindow()->draw(mBall);
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

    MathUtils::NormalizeVector(mDirection);
}

void Ball::SetDefPositionAndDirection()
{
    mBall.setPosition(Window::ScreenWidth / 2, Window::ScreenHeight / 2);

    SetRandomDirection();
}
