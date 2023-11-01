#include "HUD.h"

HUD::HUD(std::shared_ptr<Ball> ball) : mBall(ball)
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
    
    InitText(mLeftScoreText, sf::Vector2f(Window::ScreenWidth / 2 - 100, 50));
    InitText(mRightScoreText, sf::Vector2f(Window::ScreenWidth / 2 + 100, 50));

    if(mGoalSoundBuffer.loadFromFile("Sounds\\goal.mp3"))
        mGoalSound.setBuffer(mGoalSoundBuffer);
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
    if (mBall->GetPosition().x < 0)
    {
        mBall->SetNewPosition();
        mBall->SetSpeed(400.0f);
        SetLeftScore(++mLeftScore);
        
        if(mGoalSound.getBuffer())
            mGoalSound.play();
    }

    if (mBall->GetPosition().x > Window::ScreenWidth)
    {
        mBall->SetNewPosition();
        mBall->SetSpeed(400.0f);
        SetRightScore(++mRightScore);

        if(mGoalSound.getBuffer())
            mGoalSound.play();
    }
}

void HUD::SetRightScore(int score)
{
    mRightScoreText.setString(std::to_string(score));
}

void HUD::SetLeftScore(int score)
{
    mLeftScoreText.setString(std::to_string(score));
}

void HUD::Render(Window& wnd)
{
    for (const auto& elem : mDashedLine)
        wnd.Render(elem);

    wnd.Render(mLeftScoreText);
    wnd.Render(mRightScoreText);
}
