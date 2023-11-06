#pragma once
#include "IRenderable.h"
#include <SFML/Audio.hpp>
#include <random>

class Ball : public IRenderable
{
  public:
    Ball() = default;
    Ball(const sf::Vector2f& position);
    virtual void Update(float dt) override;
    virtual void Render(Window& wnd) override;
    const sf::Vector2f& GetPosition() const;
    void SetDefPositionAndDirection();
    void SetRandomDirection();
    void CollisionWithTables();
    void SetSpeed(float a) noexcept;
    float GetRadius() const noexcept;
    const sf::Vector2f& GetDirection() const;
    void SetDirection(const sf::Vector2f& direction);
    const sf::CircleShape& GetBall() const;

  private:
    void SetPosition(const sf::Vector2f& position);

  private:
    sf::CircleShape mBall;
    float mBallSpeed = 400.0f;
    float mBallRadius = 10.0f;
    sf::Vector2f mDirection;
    sf::SoundBuffer mBorderSoundBuffer;
    sf::SoundBuffer mTabletSoundBuffer;
    sf::Sound mBorderSound;
    sf::Sound mTabletSound;
    std::random_device mRd;
    std::mt19937 mGen;
    std::uniform_real_distribution<float> mDis;
};
