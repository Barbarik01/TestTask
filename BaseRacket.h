#pragma once
#include "Ball.h"
#include "IRenderable.h"

enum class SideInteract
{
    TOP_BOTTOM = 0,
    RIGHT_LEFT,
    NONE
};

class BaseRacket : public IRenderable
{
  public:
    BaseRacket(const sf::Vector2f& position, std::shared_ptr<Ball> ball, float speed, float width, float height);
    void Update(float dt) = 0;
    void Render(Window& wnd) override;
    void SetSize(const sf::Vector2f& size);
    void SetPositon(const sf::Vector2f& position);

  protected:
    void InteractWithBall();
    SideInteract IsRightSideInteract();

  protected:
    std::shared_ptr<Ball> mBall = nullptr;
    sf::RectangleShape mRacket;
    float mRacketSpeed;
    float mWidth;
    float mHeight;
    float mAngle = 0.1745f; // in radian;
};
