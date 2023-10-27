#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Window.h"

class HUD
{
public:
    HUD();
    void Update();
    void Render(Window& wnd);
    void SetRightScore(int score);
    void SetLeftScore(int score);

private:
    void InitText(sf::Text& text, const sf::Vector2f& position);
    
private:
    std::vector<sf::RectangleShape> mDashedLine;
    sf::Font mFont;
    sf::Text mLeftScore;
    sf::Text mRightScore;
   
};
