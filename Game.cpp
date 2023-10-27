#include "Game.h"
#include "BotTablet.h"
#include "PlayerTablet.h"

Game::Game(Window& wnd)
    : mWindow(wnd)
    , mLeftScore(0)
    , mRightScore(0)
    , ball(sf::Vector2f(Window::ScreenWidth / 2, Window::ScreenHeight / 2))
{
    int positionPlayerX = 10;
    int positionPlayerY = Window::ScreenHeight / 2 - BaseTablet::tabletHeight;
    sf::Vector2f playerPosition(positionPlayerX, positionPlayerY);

    int positionBotX = Window::ScreenWidth - BaseTablet::tabletWidth - 10;
    int positionBotY = Window::ScreenHeight / 2 - BaseTablet::tabletHeight;
    sf::Vector2f botPosition(positionBotX, positionBotY);

    mTablets.push_back(std::make_unique<PlayerTablet>(playerPosition));
    mTablets.push_back(std::make_unique<BotTablet>(botPosition, ball));
}

void Game::Run()
{
    mWindow.pWnd->clear();
    Update();
    Render();
    mWindow.pWnd->display();
}

void Game::Update()
{
    sf::Time deltaTime = clock.restart();
    float dt = deltaTime.asSeconds();

    ball.Update(dt);

    if (ball.GetPosition().x < 0)
    {
        ball.SetNewPosition();
        mHud.SetLeftScore(++mLeftScore);
    }

    if (ball.GetPosition().x > Window::ScreenWidth)
    {
        ball.SetNewPosition();
        mHud.SetRightScore(++mRightScore);
    }

    for (const auto& elem : mTablets)
    {
        elem->Update(dt);

        if (ball.CheckCollisionWithTables(elem.get()))
            ball.CollisionWithTables();
    }
}

void Game::Render()
{
    mHud.Render(mWindow);
    ball.Render(mWindow);

    for (const auto& elem : mTablets)
        elem->Render(mWindow);
}
