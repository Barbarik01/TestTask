#include "Game.h"
#include "BotTablet.h"
#include "PlayerTablet.h"

Game::Game()
{
    int positionPlayerX = 10;
    int positionPlayerY = Window::ScreenHeight / 2 - 100;
    sf::Vector2f playerPosition(positionPlayerX, positionPlayerY);

    int positionBotX = Window::ScreenWidth - 20;
    int positionBotY = Window::ScreenHeight / 2;
    sf::Vector2f botPosition(positionBotX, positionBotY);

    mObjects.push_back(std::make_shared<Ball>(sf::Vector2f(Window::ScreenWidth / 2, Window::ScreenHeight / 2)));
    mObjects.push_back(std::make_shared<PlayerTablet>(playerPosition, std::static_pointer_cast<Ball>(mObjects[0]), 300.0f));
    mObjects.push_back(std::make_shared<BotTablet>(botPosition, std::static_pointer_cast<Ball>(mObjects[0]), 250.0f));
    mObjects.push_back(std::make_shared<HUD>(std::static_pointer_cast<Ball>(mObjects[0])));
}

void Game::Run(float dt, Window& wnd)
{
    Update(dt);
    Render(wnd);
}

void Game::Update(float dt)
{
    for (const auto& elem : mObjects)
    {
        elem->Update(dt);
    }
}

void Game::Render(Window& wnd)
{
    for (const auto& elem : mObjects)
    {
        elem->Render(wnd);
    }
}
