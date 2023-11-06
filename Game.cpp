#include "Game.h"
#include "BotRacket.h"
#include "GameLogic.h"
#include "PlayerRacket.h"
#include "FactoryRacket.h"

Game::Game()
{
    int positionPlayerX = 10;
    int positionPlayerY = Window::ScreenHeight / 2 - 100;
    sf::Vector2f playerPosition(positionPlayerX, positionPlayerY);

    int positionBotX = Window::ScreenWidth - 20;
    int positionBotY = Window::ScreenHeight / 2;
    sf::Vector2f botPosition(positionBotX, positionBotY);

    std::shared_ptr<HUD> hud = std::make_shared<HUD>();
    std::shared_ptr<Ball> ball =
        std::make_shared<Ball>(sf::Vector2f(Window::ScreenWidth / 2, Window::ScreenHeight / 2));

    mObjects.push_back(std::make_shared<GameLogic>(ball, hud));
    mObjects.push_back(ball);
    mObjects.push_back(hud);
    mObjects.push_back(FactoryRacket::Create(TypeRacketControl::PLAYER, playerPosition, ball));
    mObjects.push_back(FactoryRacket::Create(TypeRacketControl::AI, botPosition, ball));
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
