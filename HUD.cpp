#include "HUD.h"

HUD::HUD()
{
    for (int i = 10; i < Window::ScreenHeight; i += 30)
    {
        sf::RectangleShape tempRectangle;

        tempRectangle.setSize(sf::Vector2f(3, 10));
        tempRectangle.setPosition(Window::ScreenWidth / 2, i);
        tempRectangle.setFillColor(sf::Color::White);

        mDashedLine.push_back(tempRectangle);
    }

    if (!mFont.loadFromFile("arial.ttf"))
        throw std::exception("could not load font");
    
    InitText(mLeftScoreText, sf::Vector2f(Window::ScreenWidth / 2 - 100, 50));
    InitText(mRightScoreText, sf::Vector2f(Window::ScreenWidth / 2 + 100, 50));
}

void HUD::InitText(sf::Text& text, const sf::Vector2f& position)
{
    text.setFont(mFont);
    text.setCharacterSize(30);
    text.setPosition(position);
    text.setString("0");
}

void HUD::Update(float dt)
{
}

void HUD::SetScore(const std::pair<int, int>& score)
{
    mLeftScoreText.setString(std::to_string(score.first));
    mRightScoreText.setString(std::to_string(score.second));
}

void HUD::Render(Window& wnd)
{
    for (const auto& elem : mDashedLine)
        wnd.GetWindow()->draw(elem);

    wnd.GetWindow()->draw(mLeftScoreText);
    wnd.GetWindow()->draw(mRightScoreText);
}
