#pragma once
#include "Ball.h"
#include "BaseClass.h"
#include <SFML/Graphics.hpp>
#include <vector>

class HUD : public BaseClass
{
  public:
    HUD(std::shared_ptr<Ball> ball);
    virtual void Update(float dt) override;
    virtual void Render(Window& wnd) override;
    void SetRightScore(int score);
    void SetLeftScore(int score);

  private:
    void InitText(sf::Text& text, const sf::Vector2f& position);

  private:
    std::shared_ptr<Ball> mBall;
    std::vector<sf::RectangleShape> mDashedLine;
    int mLeftScore = 0;
    int mRightScore = 0;
    sf::Font mFont;
    sf::Text mLeftScoreText;
    sf::Text mRightScoreText;
    sf::SoundBuffer mGoalSoundBuffer;
    sf::Sound mGoalSound;
};
