#pragma once
#include "Ball.h"
#include "BaseClass.h"

class Ball;

class BaseTablet : public BaseClass
{
  public:
    BaseTablet() = default;
    BaseTablet(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height);
    virtual void Update(float dt) = 0;
    virtual void Render(Window& window) override;
    virtual sf::FloatRect GetGlobalBouds() const;
    virtual bool InteractWithBall();
    virtual float GetWidth() const noexcept;
    virtual float GetHeight() const noexcept;
    virtual void SetSize(const sf::Vector2f& size);
    virtual void SetPositon(const sf::Vector2f& position);
    virtual ~BaseTablet() = default;

  protected:
    std::shared_ptr<Ball> mBall = nullptr;
    sf::RectangleShape mTablet;
    float mTabletSpeed = 300.0f;
    float mWidth;
    float mHeight;
};
