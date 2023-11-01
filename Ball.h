#pragma once
#include "BaseClass.h"
#include "BaseTablet.h"
#include <SFML/Audio.hpp>
#include <random>

class BaseTablet;

class Ball : public BaseClass
{
  public:
    Ball() = default;
    Ball(const sf::Vector2f& position);
    bool CheckCollisionWithTables(const BaseTablet& pBaseTablet) const;
    virtual void Update(float dt) override;
    virtual void Render(Window& window) override;
    const sf::Vector2f& GetPosition() const;
    void SetNewPosition();
    void SetRandomDirection();
    void CollisionWithTables();
    void SetSpeed(float a) noexcept;
    float GetRadius() const noexcept;

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
