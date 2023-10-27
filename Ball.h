#pragma once
#include "Window.h"
#include <SFML/Audio.hpp>
#include "BaseTablet.h"

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
    sf::CircleShape ball;
    float ballSpeed = 400.0f;
    sf::Vector2f direction;
    sf::SoundBuffer borderSoundBuffer;
    sf::SoundBuffer tabletSoundBuffer;
    sf::Sound borderSound;
    sf::Sound tabletSound;
};
