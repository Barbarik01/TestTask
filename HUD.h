#pragma once
#include "Ball.h"
#include "IRenderable.h"
#include <SFML/Graphics.hpp>
#include <vector>

class HUD : public IRenderable
{
  public:
    HUD();
    virtual void Update(float dt) override;
    virtual void Render(Window& wnd) override;
    void SetScore(const std::pair<int, int>& score);

  private:
    void InitText(sf::Text& text, const sf::Vector2f& position);

  private:
    std::vector<sf::RectangleShape> mDashedLine;
    sf::Font mFont;
    sf::Text mLeftScoreText;
    sf::Text mRightScoreText;
};
