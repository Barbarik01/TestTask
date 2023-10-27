#pragma once
#include "Window.h"

class BaseTablet {
public:
    BaseTablet() = default;
    BaseTablet(const sf::Vector2f& position);
    virtual bool CheckCollision() const;
    virtual void Update(float dt) = 0;
    virtual void Render(Window& window);
    virtual sf::FloatRect GetGlobalBouds() const;
    virtual ~BaseTablet() = default;

public:
    static constexpr float tabletWidth = 10.0f;
    static constexpr float tabletHeight = 100.0f;

protected:
    sf::RectangleShape mTablet;
    const float mTabletSpeed = 300.0f;
};
