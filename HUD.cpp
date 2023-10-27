#include "HUD.h"
#include <sstream>

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

    mFont.loadFromFile("arial.ttf");

    InitText(mLeftScore, sf::Vector2f(Window::ScreenWidth / 2 - 100, 50));
    InitText(mRightScore, sf::Vector2f(Window::ScreenWidth / 2 + 100, 50));
}

void HUD::InitText(sf::Text& text, const sf::Vector2f& position)
{
    text.setFont(mFont);
    text.setCharacterSize(30);
    text.setPosition(position);
    text.setString("0");
}

void HUD::Update()
{
}

void HUD::SetRightScore(int score)
{
    std::stringstream ss;
    ss << score;
    mRightScore.setString(ss.str());
}

void HUD::SetLeftScore(int score)
{
    std::stringstream ss;
    ss << score;
    mLeftScore.setString(ss.str());
}

void HUD::Render(Window& wnd)
{
    for (const auto& elem : mDashedLine)
        wnd.pWnd->draw(elem);

    wnd.pWnd->draw(mLeftScore);
    wnd.pWnd->draw(mRightScore);
}
