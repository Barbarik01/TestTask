#include "Ball.h"
#include <random>

Ball::Ball(const sf::Vector2f& position)
{
    mBall.setRadius(ballRadius);
    mBall.setPosition(position);
    mBall.setFillColor(sf::Color::White);

    SetRandomDirection();

    mBorderSoundBuffer.loadFromFile("Sounds\\BorderSound.mp3");
    mTabletSoundBuffer.loadFromFile("Sounds\\TabletSound.mp3");
    mBorderSound.setBuffer(mBorderSoundBuffer);
    mTabletSound.setBuffer(mTabletSoundBuffer);
}

void Ball::SetPosition(const sf::Vector2f& position)
{
    mBall.setPosition(position);
}

bool Ball::CheckCollisionWithTables(const BaseTablet* pBaseTablet) const
{
    return mBall.getGlobalBounds().intersects(pBaseTablet->GetGlobalBouds());
}

void Ball::CollisionWithTables()
{
    mDirection.x = -mDirection.x;
    mTabletSound.play();
}

void Ball::Update(float dt)
{
    mBall.move(mDirection.x * mBallSpeed * dt, mDirection.y * mBallSpeed * dt);

    if (mBall.getPosition().y < 0 || mBall.getPosition().y + ballRadius * 2 > Window::ScreenHeight)
    {
        mDirection.y = -mDirection.y;
        mBorderSound.play();
    }
}

void Ball::Render(Window& window)
{
    window.pWnd->draw(mBall);
}

const sf::Vector2f& Ball::GetPosition() const
{
    return mBall.getPosition();
}

void Ball::SetRandomDirection()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    std::uniform_int_distribution<> disInt(-1, 1);
    
    do
    {
        mDirection.x = disInt(gen);
    } while (mDirection.x == 0);
    
    mDirection.y = dis(gen);
}

void Ball::SetNewPosition()
{
    mBall.setPosition(Window::ScreenWidth / 2, Window::ScreenHeight / 2);

    SetRandomDirection();
}
