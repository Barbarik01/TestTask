#pragma once
#include "BaseTablet.h"
#include "Window.h"
#include <SFML/Audio.hpp>

class Ball
{
  public:
    Ball() = default;
    Ball(const sf::Vector2f& position);
    bool CheckCollisionWithTables(const BaseTablet* pBaseTablet) const;
    void Update(float dt);
    void Render(Window& window);
    const sf::Vector2f& GetPosition() const;
    void SetNewPosition();
    void SetRandomDirection();
    void CollisionWithTables();

  private:
    void SetPosition(const sf::Vector2f& position);

  public:
    static constexpr float ballRadius = 10.0f;

  private:
    sf::CircleShape mBall;
    float mBallSpeed = 400.0f;
    sf::Vector2f mDirection;
    sf::SoundBuffer mBorderSoundBuffer;
    sf::SoundBuffer mTabletSoundBuffer;
    sf::Sound mBorderSound;
    sf::Sound mTabletSound;
};
