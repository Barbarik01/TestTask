#include "Ball.h"
#include <random>

Ball::Ball(const sf::Vector2f& position)
{
    ball.setRadius(ballRadius);
    ball.setPosition(position);
    ball.setFillColor(sf::Color::White);

    SetRandomDirection();

    borderSoundBuffer.loadFromFile("Sounds\\BorderSound.mp3");
    tabletSoundBuffer.loadFromFile("Sounds\\TabletSound.mp3");
    borderSound.setBuffer(borderSoundBuffer);
    tabletSound.setBuffer(tabletSoundBuffer);
}

void Ball::SetPosition(const sf::Vector2f& position)
{
    ball.setPosition(position);
}

bool Ball::CheckCollisionWithTables(const BaseTablet* pBaseTablet) const
{
    return ball.getGlobalBounds().intersects(pBaseTablet->getGlobalBouds());
}

void Ball::CollisionWithTables()
{
    direction.x = -direction.x;
    tabletSound.play();
}

void Ball::Update(float dt)
{
    ball.move(direction.x * ballSpeed * dt, direction.y * ballSpeed * dt);

    if (ball.getPosition().y < 0 || ball.getPosition().y + ballRadius * 2 > Window::ScreenHeight)
    {
        direction.y = -direction.y;
        borderSound.play();
    }
}

void Ball::Render(Window& window)
{
    window.pWnd->draw(ball);
}

const sf::Vector2f& Ball::GetPosition() const
{
    return ball.getPosition();
}

void Ball::SetRandomDirection()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    std::uniform_int_distribution<> disInt(-1, 1);
    
    do
    {
        direction.x = disInt(gen);
    } while (direction.x == 0);
    
    direction.y = dis(gen);
}

void Ball::SetNewPosition()
{
    ball.setPosition(Window::ScreenWidth / 2, Window::ScreenHeight / 2);

    SetRandomDirection();
}
